#ifndef ENEMY_H
#define ENEMY_H

#include <QPixmap>
#include <QRect>
#include <QString>
#include "flyingobject.h"

namespace stg
{
    class Enemy:public FlyingObject
    {
    public:
        Enemy(qreal x=0,qreal y=0,int maxhp=0,qreal facex=0,qreal facey=0);
        void setHp(int value);
        int maxhp;
        int hp;
    };

    class Boss:public Enemy
    {
    public:
        Boss(qreal x,qreal y,int maxhp,qreal facex,qreal facey);
        QPixmap bosspixmaps[4];
        void RenewBossStage();
        int bossstage;
        bool isCollidingwithHeroBullet(FlyingObject *herobullet);
    };

    class Zako:public Enemy{
    public:
        Zako(qreal x,qreal y,int maxhp,qreal facex,qreal facey);
        bool isCollidingwithHeroBullet(FlyingObject *herobullet);
    };
}
#endif // ENEMY_H
