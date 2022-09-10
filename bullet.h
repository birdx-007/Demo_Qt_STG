#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>
#include <QRect>
#include "flyingobject.h"

namespace stg
{
    class Bullet:public FlyingObject
    {
    public:
        Bullet(qreal x,qreal y,qreal facex,qreal facey);
        qreal bullet_speed;
        int bullet_ap;
    };

    class MainBullet:public Bullet
    {
    public:
        MainBullet(qreal x,qreal y,qreal facex,qreal facey);
    };

    class AuxiliaryBullet:public Bullet
    {
    public:
        AuxiliaryBullet(qreal x,qreal y,qreal facex,qreal facey);
    };

    class EnemyBullet:public Bullet
    {
    public:
        EnemyBullet(qreal x,qreal y,qreal facex,qreal facey,QString flytype);
        bool isCollidingwithHero(FlyingObject *hero);
        QString flyingtype;
    };

    class Ball:public EnemyBullet
    {
    public:
        Ball(qreal x,qreal y,qreal facex,qreal facey,QString flytype,QString colortype);
    };
}


#endif // BULLET_H
