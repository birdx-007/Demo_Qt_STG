#ifndef HERO_H
#define HERO_H

#include <QPixmap>
#include <QRect>
#include "flyingobject.h"

namespace stg
{
    class Hero:public FlyingObject
    {
    public:
        Hero();
        void setPosition(qreal x,qreal y,qreal facex,qreal facey);
        bool isShooting;
    };
}
#endif // HERO_H
