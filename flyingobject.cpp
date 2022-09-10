#include "flyingobject.h"
namespace stg
{
    FlyingObject::FlyingObject(qreal x,qreal y,qreal facex,qreal facey)
    {
        this->setPosition(x,y,facex,facey);
        this->rect.setWidth(1);
        this->rect.setHeight(1);
        this->type=QString("ufo");
        this->isValid=true;
    }

    void FlyingObject::setPosition(qreal x, qreal y, qreal facex, qreal facey)
    {
        this->X=x;
        this->Y=y;
        this->rect.moveTo(this->X,this->Y);
        this->facingdirectionX=facex;
        this->facingdirectionY=facey;
    }

    qreal FlyingObject::facingXYtoAngle()
    {
        //返回角度而非弧度
        return qAtan2(this->facingdirectionY,this->facingdirectionX)/M_PI*180+90;
    }
}

