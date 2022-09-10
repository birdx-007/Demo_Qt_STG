#include "managerdep.h"
namespace stg
{
    ManagerDep::ManagerDep(QObject *parent) : QObject(parent)
    {
        this->danmakumanager.SetManagers(&this->bulletmanager,&this->enemymanager);
    }

    void ManagerDep::SetHero(Hero *hero_)
    {
        this->hero=&*hero_;
    }

    void ManagerDep::ManageCollisions()
    {
        std::vector<Boss>::iterator bossiter;
        for(bossiter=this->enemymanager.bosses.begin();bossiter!=this->enemymanager.bosses.end();bossiter++)
        {
            std::vector<Bullet>::iterator bulletiter;
            for(bulletiter=this->bulletmanager.herobullets.begin();bulletiter!=this->bulletmanager.herobullets.end();bulletiter++)
            {
                bool isCollided=bossiter->isCollidingwithHeroBullet(&*bulletiter);
                //bulletiter->isValid=!isCollided;
            }
        }

        std::vector<EnemyBullet>::iterator enemybulletiter;
        for(enemybulletiter=this->bulletmanager.enemybullets.begin();enemybulletiter!=this->bulletmanager.enemybullets.end();enemybulletiter++)
        {
            bool isCollided=enemybulletiter->isCollidingwithHero(&*this->hero);
            //this->hero->isValid=!isCollided;
        }
    }

    void ManagerDep::ManageHeroMainBulletsMoving()
    {
        std::vector<Bullet>::iterator iter;
        for(iter=this->bulletmanager.herobullets.begin();iter!=this->bulletmanager.herobullets.end();iter++)
        {
            if(iter->type==QString("mainbullet"))
                this->bulletmanager.MoveOneHeroMainBullet(&*iter);
        }
    }

    void ManagerDep::ManageHeroAuxiliaryBulletsMoving()
    {
        std::vector<Bullet>::iterator bulletiter;
        std::vector<Boss>::iterator bossiter;
        std::vector<Zako>::iterator zakoiter;
        for(bulletiter=this->bulletmanager.herobullets.begin();bulletiter!=this->bulletmanager.herobullets.end();bulletiter++)
        {
            if(bulletiter->type==QString("auxiliarybullet"))
            {
                double mindistancesquare=1500*1500;
                Enemy target;
                for(bossiter=this->enemymanager.bosses.begin();bossiter!=this->enemymanager.bosses.end();bossiter++)
                {
                    qreal deltaX=qAbs(bossiter->X+bossiter->rect.width()/2-bulletiter->X);
                    qreal deltaY=qAbs(bossiter->Y+bossiter->rect.height()/2-bulletiter->Y);
                    double tmpdistancesquare=deltaX*deltaX+deltaY*deltaY;
                    if(tmpdistancesquare<mindistancesquare)
                    {
                        mindistancesquare=tmpdistancesquare;
                        target=*bossiter;
                    }
                }
                for(zakoiter=this->enemymanager.zakos.begin();zakoiter!=this->enemymanager.zakos.end();zakoiter++)
                {
                    qreal deltaX=qAbs(zakoiter->X-bulletiter->X);
                    qreal deltaY=qAbs(zakoiter->Y-bulletiter->Y);
                    qreal tmpdistancesquare=deltaX*deltaX+deltaY*deltaY;
                    if(tmpdistancesquare<mindistancesquare)
                    {
                        mindistancesquare=tmpdistancesquare;
                        target=*zakoiter;
                    }
                }
                //已找到与子弹间距最小的敌人
                if(this->enemymanager.bosses.size()==0&&this->enemymanager.zakos.size()==0)
                {
                    this->bulletmanager.MoveOneHeroMainBullet(&*bulletiter);
                }
                else
                {
                    this->bulletmanager.MoveOneAuxiliaryBullet(&*bulletiter,&target);
                }

            }
        }
    }

    void ManagerDep::ManageEnemyBulletsMoving()
    {
        std::vector<EnemyBullet>::iterator bulletiter;
        for(bulletiter=this->bulletmanager.enemybullets.begin();bulletiter!=this->bulletmanager.enemybullets.end();bulletiter++)
        {
            this->bulletmanager.MoveOneEnemyBullet(&*bulletiter,this->hero);
        }
    }

    void ManagerDep::DestoryInvalidObjects()
    {
        this->bulletmanager.DestoryInvalidBullets();
        this->enemymanager.DestoryInvalidBosses();
    }

    void ManagerDep::DestoryAllObjects()
    {
        this->bulletmanager.DestoryAllEnemyBullets();
        this->enemymanager.DestoryAllBosses();
    }

    void ManagerDep::GenerateSpellCard(int counter)//随游戏进程生成弹幕
    {
        if(counter>100&&counter%(70-enemymanager.bosses[0].bossstage*15)==0&&this->enemymanager.bosses.size()>0)
        {
            qreal x=this->enemymanager.bosses[0].X+this->enemymanager.bosses[0].rect.width()/2;
            qreal y=this->enemymanager.bosses[0].Y+this->enemymanager.bosses[0].rect.height()/2;
            this->danmakumanager.AddOneCircle(x,y,enemymanager.bosses[0].bossstage*10);
            this->danmakumanager.AddOneAim(this->hero,x,y,3,M_PI/8,"ball","purple");
        }
    }
}
