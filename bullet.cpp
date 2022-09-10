#include "bullet.h"

namespace stg
{
    Bullet::Bullet(qreal x,qreal y,qreal facex,qreal facey):FlyingObject(x,y,facex,facey)
    {
        this->setPosition(x,y,facex,facey);
        this->type=QString("bullet");
    }
}
