#include "enemymanager.h"
namespace stg
{
    EnemyManager::EnemyManager(QObject *parent) : QObject(parent)
    {

    }

    void EnemyManager::AddOneBoss(int maxhp, qreal x, qreal y)
    {
        Boss newboss(x,y,maxhp,0,-1);
        this->bosses.push_back(newboss);
    }

    void EnemyManager::MoveBoss(int counter)//根据游戏进程/位置移动boss
    {
        std::vector<Boss>::iterator iter;
        for(iter=this->bosses.begin();iter!=this->bosses.end();iter++)
        {
            qreal x=iter->X;
            qreal y=iter->Y;
            if(counter>=85&&counter<=100)
            {
                iter->setPosition(x,y+400*(qExp(-(qreal)counter/80)-0.25),0,-1);
            }
            else if(counter>100)
            {
                iter->RenewBossStage();
                //int deltax=x-1063/2;
                //int direction=(counter/100%4<2)?-1:1;
                qreal speed=5*qSin(qreal((counter-100)%400)*M_PI/200.0);
                //int newx=(iter->bossstage*120)*qSin(qreal((counter-100)%400)*M_PI/200.0)+400;
                iter->setPosition(x+(int)speed,y,speed/10,-1);
            }

        }
    }

    void EnemyManager::DestoryInvalidBosses()
    {
        std::vector<Boss>::iterator iter;
        for(iter=this->bosses.begin();iter!=this->bosses.end();iter++)
        {
            int x=iter->X;
            int y=iter->Y;
            if(!(x>=-400&&x<=1480&&y>=-400&&y<=1480)||iter->hp==0)
            {
                std::vector<Boss>::iterator tmpiter=iter;
                this->bosses.erase(tmpiter);
                iter--;
            }
        }
    }

    void EnemyManager::DestoryAllBosses()
    {
        std::vector<Boss>::iterator iter;
        for(iter=this->bosses.begin();iter!=this->bosses.end();iter++)
        {
            std::vector<Boss>::iterator tmpiter=iter;
            this->bosses.erase(tmpiter);
            iter--;
        }
    }
}
