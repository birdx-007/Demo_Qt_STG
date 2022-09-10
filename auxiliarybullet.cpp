#include "bullet.h"
namespace stg
{
    AuxiliaryBullet::AuxiliaryBullet(qreal x,qreal y,qreal facex,qreal facey):Bullet(x,y,facex,facey)
    {
        this->pixmap.load(":/res/bullet2.png");
        this->rect.setWidth(this->pixmap.width());
        this->rect.setHeight(this->pixmap.height());
        this->rect.moveTo(this->X,this->Y);
        this->bullet_speed=20;
        this->bullet_ap=3;
        this->type=QString("auxiliarybullet");
    }
}
