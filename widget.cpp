#include "widget.h"
namespace stg
{
    Widget::Widget(QWidget *parent)
        : QWidget(parent)
    {
        initScene();
        playGame();
    }

    Widget::~Widget()
    {
    }

    void Widget::initScene()//初始化场景各元素
    {
        counter=0;
        setFixedSize(1063,1063);
        setWindowTitle("QWQ");
        setWindowIcon(QIcon(":/res/hero.png"));
        m_Timer.setInterval(10);

        this->m_managerDep.SetHero(&this->m_hero);
        this->m_managerDep.enemymanager.AddOneBoss(6000,400-250,-300);
    }

    void Widget::playGame()
    {
        m_Timer.start();
        connect(&m_Timer,&QTimer::timeout,[=]()
        {
            this->counter++;
            this->setWindowTitle(QString("%1 counter=%2 bullet(s)=%3 fps=%4")
                                 .arg(this->m_hero.isValid?"QwQ":"GameOver")
                                 .arg(this->counter)
                                 .arg(this->m_managerDep.bulletmanager.herobullets.size()+this->m_managerDep.bulletmanager.enemybullets.size())
                                 .arg(1000/m_Timer.interval()));

            updateAllPosition();//处理键盘事件及数据、更新元素位置
            update();//绘图
        });
    }

    void Widget::updateAllPosition()
    {
        this->m_map.updateMapPosition();

        this->m_vector.GenerateVector();
        int isShiftPressed=this->m_vector.StateofMoveKeys[4]==QString("pressed")?1:0;
        qreal deltax=this->m_vector.Vx*200000.0/(20000+isShiftPressed*30000);
        qreal deltay=this->m_vector.Vy*200000.0/(20000+isShiftPressed*30000);
        this->m_hero.setPosition(this->m_hero.X+deltax,this->m_hero.Y+deltay,0,-1);
        if(!this->m_hero.isValid)
            this->m_hero.setPosition(1063*0.5-this->m_hero.pixmap.width()*0.5,1063-this->m_hero.pixmap.height(),0,-1);

        this->m_managerDep.enemymanager.MoveBoss(this->counter);
        this->m_managerDep.GenerateSpellCard(this->counter);

        this->m_managerDep.ManageEnemyBulletsMoving();
        this->m_managerDep.ManageHeroMainBulletsMoving();
        this->m_managerDep.ManageHeroAuxiliaryBulletsMoving();

        if(this->m_hero.isValid&&this->m_hero.isShooting&&this->counter%8==0)
        {
            this->m_managerDep.bulletmanager.AddOneHeroBullet(QString("mainbullet"),this->m_hero.X+this->m_hero.pixmap.width()-17,this->m_hero.Y);
            this->m_managerDep.bulletmanager.AddOneHeroBullet(QString("mainbullet"),this->m_hero.X+5,this->m_hero.Y);
            this->m_managerDep.bulletmanager.AddOneHeroBullet(QString("auxiliarybullet"),this->m_hero.X-20,this->m_hero.Y);
            this->m_managerDep.bulletmanager.AddOneHeroBullet(QString("auxiliarybullet"),this->m_hero.X+this->m_hero.pixmap.width()+10,this->m_hero.Y);
            this->m_managerDep.bulletmanager.AddOneHeroBullet(QString("auxiliarybullet"),this->m_hero.X-50+isShiftPressed*25,this->m_hero.Y-20-isShiftPressed*25);
            this->m_managerDep.bulletmanager.AddOneHeroBullet(QString("auxiliarybullet"),this->m_hero.X+this->m_hero.pixmap.width()+40-isShiftPressed*25,this->m_hero.Y-20-isShiftPressed*25);
        }

        this->m_managerDep.ManageCollisions();

        this->m_managerDep.DestoryInvalidObjects();
    }

    void Widget::paintEvent(QPaintEvent *event)//可通过调整这里的绘制顺序调节各元素的显示次序
    {
        Q_UNUSED(event);
        QPainter painter(this);

        painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
        painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

        foreach(Boss boss,this->m_managerDep.enemymanager.bosses)
        {
            boss.RenewBossStage();
            painter.save();
            painter.translate(boss.rect.center());
            painter.rotate(boss.facingXYtoAngle());
            painter.translate(-boss.rect.center());
            painter.drawPixmap(boss.X,boss.Y,boss.bosspixmaps[boss.bossstage]);
            painter.restore();
        }

        foreach(Bullet herobullet,this->m_managerDep.bulletmanager.herobullets)
        {
            painter.save();
            painter.translate(herobullet.rect.center());
            painter.rotate(herobullet.facingXYtoAngle());
            painter.translate(-herobullet.rect.center());
            painter.drawPixmap(herobullet.X,herobullet.Y,herobullet.pixmap);
            painter.restore();
        }

        if(m_hero.isValid)
        {
            painter.save();
            painter.translate(m_hero.rect.center());
            painter.rotate(m_hero.facingXYtoAngle());
            painter.translate(-m_hero.rect.center());
            painter.drawPixmap(m_hero.X,m_hero.Y,m_hero.pixmap);
            painter.restore();
            int isShiftPressed=this->m_vector.StateofMoveKeys[4]==QString("pressed")?1:0;
            if(isShiftPressed==1)
            {
                painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
                painter.drawRect(m_hero.rect);
            }

        }

        foreach(EnemyBullet enemybullet,this->m_managerDep.bulletmanager.enemybullets)
        {
            painter.save();
            painter.translate(enemybullet.rect.center());
            painter.rotate(enemybullet.facingXYtoAngle());
            painter.translate(-enemybullet.rect.center());
            painter.drawPixmap(enemybullet.X,enemybullet.Y,enemybullet.pixmap);
            painter.restore();
        }

        if(this->m_hero.isValid==false)
        {
            painter.setPen(QPen(Qt::white));
            painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
            //painter.drawRect(250,300,600,400);
            painter.drawPixmap(250,300,QPixmap(":/res/gameover.png"));
            painter.restore();
        }
    }

    void Widget::keyPressEvent(QKeyEvent *event)
    {
        if(event->key()==Qt::Key_Left)
        {
            this->m_vector.StateofMoveKeys[0]=QString("pressed");
        }
        if(event->key()==Qt::Key_Right)
        {
            this->m_vector.StateofMoveKeys[3]=QString("pressed");
        }
        if(event->key()==Qt::Key_Up)
        {
            this->m_vector.StateofMoveKeys[1]=QString("pressed");
        }
        if(event->key()==Qt::Key_Down)
        {
            this->m_vector.StateofMoveKeys[2]=QString("pressed");
        }
        if(event->key()==Qt::Key_Shift)
        {
            this->m_vector.StateofMoveKeys[4]=QString("pressed");
        }
        if(event->key()==Qt::Key_Z)
        {
            this->m_hero.isShooting=true;
        }
    }

    void Widget::keyReleaseEvent(QKeyEvent *event)
    {
        if(event->key()==Qt::Key_Left)
        {
            this->m_vector.StateofMoveKeys[0]=QString("unpressed");
        }
        if(event->key()==Qt::Key_Right)
        {
            this->m_vector.StateofMoveKeys[3]=QString("unpressed");
        }
        if(event->key()==Qt::Key_Up)
        {
            this->m_vector.StateofMoveKeys[1]=QString("unpressed");
        }
        if(event->key()==Qt::Key_Down)
        {
            this->m_vector.StateofMoveKeys[2]=QString("unpressed");
        }
        if(event->key()==Qt::Key_Shift)
        {
            this->m_vector.StateofMoveKeys[4]=QString("unpressed");
        }
        if(event->key()==Qt::Key_Z)
        {
            this->m_hero.isShooting=false;
        }
        if((this->m_hero.isValid==false||this->m_managerDep.enemymanager.bosses.size()==0)&&event->key()==Qt::Key_X)
        {
            this->m_managerDep.DestoryAllObjects();
            this->m_hero.isValid=true;
            this->initScene();
        }
    }
}


