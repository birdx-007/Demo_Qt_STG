#include <bullet.h>

namespace stg
{
    EnemyBullet::EnemyBullet(qreal x,qreal y,qreal facex,qreal facey,QString flytype):Bullet(x,y,facex,facey)
    {
        this->flyingtype=flytype;
    }

    bool EnemyBullet::isCollidingwithHero(FlyingObject *hero)
    {
        bool condition_1=this->rect.contains(hero->rect.topLeft());
        bool condition_2=this->rect.contains(hero->rect.topRight());
        bool condition_3=this->rect.contains(hero->rect.bottomLeft());
        bool condition_4=this->rect.contains(hero->rect.bottomRight());
        if(hero->isValid&&(condition_1||condition_2||condition_3||condition_4))
        {
            this->isValid=false;
            hero->isValid=false;
            return true;
        }
        else return false;
    }
}
