#include "enemy.h"
namespace stg
{
    Enemy::Enemy(qreal x,qreal y,int maxhp,qreal facex,qreal facey):FlyingObject(x,y,facex,facey)
    {
        this->setPosition(x,y,facex,facey);
        this->maxhp=maxhp;
        this->hp=maxhp;
        this->type=QString("enemy");
    }

    void Enemy::setHp(int value)
    {
        this->hp=(value>=0)?(value<=this->maxhp?value:this->maxhp):0;
    }
}
