#include "enemy.h"
namespace stg
{
    Boss::Boss(qreal x,qreal y,int maxhp,qreal facex,qreal facey):Enemy(x,y,maxhp,facex,facey)
    {
        this->bosspixmaps[0].load(":/res/boss_0.png");
        this->bosspixmaps[1].load(":/res/boss_1.png");
        this->bosspixmaps[2].load(":/res/boss_2.png");
        this->bosspixmaps[3].load(":/res/boss_3.png");
        this->rect.setWidth(this->bosspixmaps[0].width());
        this->rect.setHeight(this->bosspixmaps[0].height());
        this->bossstage=0;
        this->type=QString("boss");
    }

    void Boss::RenewBossStage()
    {
        if(this->hp==this->maxhp)
        {
            this->bossstage=0;
        }
        else if(this->hp>=this->maxhp/3*2)
        {
            this->bossstage=1;
        }
        else if(this->hp>=this->maxhp/3)
        {
            this->bossstage=2;
        }
        else
        {
            this->bossstage=3;
        }
    }

    bool Boss::isCollidingwithHeroBullet(FlyingObject *herobullet)
    {
        bool condition_1=this->rect.contains(herobullet->rect.topLeft());
        bool condition_2=this->rect.contains(herobullet->rect.topRight());
        bool condition_3=this->rect.contains(herobullet->rect.bottomLeft());
        bool condition_4=this->rect.contains(herobullet->rect.bottomRight());
        if(condition_1||condition_2||condition_3||condition_4)
        {
            if(herobullet->type==QString("mainbullet"))
            {
                this->setHp(this->hp-6);
                herobullet->isValid=false;
            }
            if(herobullet->type==QString("auxiliarybullet"))
            {
                this->setHp(this->hp-3);
                herobullet->isValid=false;
            }
            return true;
        }
        else return false;
    }
}
