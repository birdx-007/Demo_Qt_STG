#include "hero.h"
namespace stg
{
    Hero::Hero():FlyingObject()
    {
        //初始化加载飞机图片资源
        this->pixmap.load(":/res/hero.png");
        //初始化坐标
        this->X=1063*0.5-this->pixmap.width()*0.5;
        this->Y=1063-this->pixmap.height();
        //初始化矩形框
        this->rect.setWidth(2);
        this->rect.setHeight(2);
        this->rect.moveTo(this->X+this->pixmap.width()/2-1,this->Y+this->pixmap.height()/2-1);
        isShooting=false;
        this->type=QString("hero");
    }

    void Hero::setPosition(qreal x, qreal y, qreal facex, qreal facey)
    {
        int isXOverflow=(x>=-9&&x<=1013)?0:1;
        int isYOverflow=(y>=0&&y<=1013)?0:1;
        this->X=isXOverflow?this->X:x;
        this->Y=isYOverflow?this->Y:y;
        this->rect.moveTo(this->X+this->pixmap.width()/2-1,this->Y+this->pixmap.height()/2-1);
        this->facingdirectionX=facex;
        this->facingdirectionY=facey;
    }
}
