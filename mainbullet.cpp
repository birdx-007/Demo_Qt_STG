#include "bullet.h"
namespace stg
{
    MainBullet::MainBullet(qreal x,qreal y,qreal facex,qreal facey):Bullet(x,y,facex,facey)
    {
        this->pixmap.load(":/res/bullet1.png");
        this->rect.setWidth(this->pixmap.width());
        this->rect.setHeight(this->pixmap.height());
        this->rect.moveTo(this->X,this->Y);
        this->bullet_speed=20;
        this->bullet_ap=6;
        this->type=QString("mainbullet");
    }
}

