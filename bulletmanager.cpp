#include "bulletmanager.h"
namespace stg
{
    BulletManager::BulletManager(QObject *parent) : QObject(parent)
    {

    }

    void BulletManager::AddOneHeroBullet(QString type,int x,int y)
    {
        if(type==QString("mainbullet"))
        {
            MainBullet newherobullet(x,y,0,-1);
            this->herobullets.push_back(newherobullet);
        }
        else if(type==QString("auxiliarybullet"))
        {
            AuxiliaryBullet newherobullet(x,y,0,-1);
            this->herobullets.push_back(newherobullet);
        }
    }

    void BulletManager::AddOneBall(qreal x, qreal y, qreal facex, qreal facey, QString flytype, QString color)
    {
        Ball newball(x,y,facex,facey,flytype,color);
        this->enemybullets.push_back(newball);
    }

    void BulletManager::MoveOneHeroMainBullet(Bullet *bullet)
    {
        qreal deltay=bullet->bullet_speed;
        bullet->setPosition(bullet->X,bullet->Y-deltay,0,-1);
    }

    void BulletManager::MoveOneAuxiliaryBullet(Bullet *bullet, FlyingObject *target)
    {
        qreal bulletx=bullet->X,bullety=bullet->Y;
        qreal targetx=target->X+target->rect.width()/2,targety=target->Y+target->rect.height()/2;
        qreal deltax=qAbs(bulletx-targetx),deltay=qAbs(bullety-targety);
        qreal length=qSqrt(deltax*deltax+deltay*deltay);
        qreal facingx=(targetx-bulletx)/length;
        qreal facingy=(targety-bullety)/length;
        qreal bulletnewx=bulletx+facingx*bullet->bullet_speed;
        qreal bulletnewy=bullety+facingy*bullet->bullet_speed;
        bullet->setPosition(bulletnewx,bulletnewy,facingx,facingy);
    }

    void BulletManager::MoveOneEnemyBullet(EnemyBullet *bullet, FlyingObject *target)
    {
        if(bullet->flyingtype==QString("line"))
        {
            Q_UNUSED(target);
            qreal bulletx=bullet->X,bullety=bullet->Y;
            qreal facingx=bullet->facingdirectionX,facingy=bullet->facingdirectionY;
            //qreal facinglength=qSqrt(facingx*facingx+facingy*facingy);
            //facingx=facingx/facinglength;facingy=facingy/facinglength;
            //假设已归一化向量，减少计算
            qreal deltax=facingx*bullet->bullet_speed;
            qreal deltay=facingy*bullet->bullet_speed;
            bullet->setPosition(bulletx+deltax,bullety+deltay,facingx,facingy);
            //直线运动
        }
        else if(bullet->flyingtype==QString("tracking"))
        {
            if(target!=NULL&&target->isValid)
            {
                qreal bulletx=bullet->X,bullety=bullet->Y;
                qreal targetx=target->X+target->rect.width()/2,targety=target->Y+target->rect.height()/2;
                qreal deltax=targetx-bulletx,deltay=targety-bullety;
                qreal distance=qSqrt(deltax*deltax+deltay*deltay);
                if(distance>=500)
                {
                    bullet->flyingtype=QString("tracking");
                    qreal targetangle=(qAtan2(deltay,deltax))*(500.0/distance);//向目标偏移一半角度
                    qreal facingx=(bullet->facingdirectionX+qCos(targetangle));
                    qreal facingy=(bullet->facingdirectionY+qSin(targetangle));
                    qreal length=qSqrt(facingx*facingx+facingy*facingy);
                    facingx/=length;
                    facingy/=length;
                    qreal bulletnewx=bulletx+facingx*bullet->bullet_speed;
                    qreal bulletnewy=bullety+facingy*bullet->bullet_speed;
                    bullet->setPosition(bulletnewx,bulletnewy,facingx,facingy);
                    //半追击运动（曲线激光）
                }
                else
                {
                    bullet->flyingtype=QString("line");
                }
            }
            else
            {
                bullet->flyingtype=QString("line");
            }

        }
    }


    void BulletManager::DestoryInvalidBullets()
    {
        std::vector<Bullet>::iterator iter;
        for(iter=this->herobullets.begin();iter!=this->herobullets.end();iter++)//自机子弹
        {
            qreal x=iter->X;
            qreal y=iter->Y;
            if(!(x>=-140&&x<=1200&&y>=-140&&y<=1200)||!iter->isValid)
            {
                std::vector<Bullet>::iterator tmpiter=iter;
                this->herobullets.erase(tmpiter);
                iter--;
            }
        }
        std::vector<EnemyBullet>::iterator iter1;
        for(iter1=this->enemybullets.begin();iter1!=this->enemybullets.end();iter1++)//敌机子弹
        {
            qreal x=iter1->X;
            qreal y=iter1->Y;
            if(!(x>=-140&&x<=1200&&y>=-140&&y<=1200)||!iter1->isValid)
            {
                std::vector<EnemyBullet>::iterator tmpiter=iter1;
                this->enemybullets.erase(tmpiter);
                iter1--;
            }
        }
    }

    void BulletManager::DestoryAllEnemyBullets()
    {
        std::vector<EnemyBullet>::iterator iter1;
        for(iter1=this->enemybullets.begin();iter1!=this->enemybullets.end();iter1++)//敌机子弹
        {
            std::vector<EnemyBullet>::iterator tmpiter=iter1;
            this->enemybullets.erase(tmpiter);
            iter1--;
        }
    }
}
