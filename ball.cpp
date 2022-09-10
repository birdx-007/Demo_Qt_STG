#include "bullet.h"
namespace stg
{
    Ball::Ball(qreal x,qreal y,qreal facex,qreal facey,QString flytype,QString colortype):EnemyBullet(x,y,facex,facey,flytype)
    {
        if(colortype==QString("blue"))
        {
            this->pixmap.load(":/res/ballblue.png");
        }
        else if(colortype==QString("red"))
        {
            this->pixmap.load(":/res/ballred.png");
        }
        else if(colortype==QString("purple"))
        {
            this->pixmap.load(":/res/ballpurple.png");
        }
        this->rect.setWidth(this->pixmap.width());
        this->rect.setHeight(this->pixmap.height());
        this->rect.moveTo(this->X,this->Y);
        this->bullet_speed=5;
        this->bullet_ap=1;
        this->type=QString("ball");
    }
}
