#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include <QPixmap>
#include <QRect>
#include <QtMath>
#include <QString>
namespace stg
{
    class FlyingObject
    {
    public:
        FlyingObject(qreal x=1063/2,qreal y=-100,qreal facex=0,qreal facey=-1);
        bool isValid;
        qreal X;
        qreal Y;
        qreal facingdirectionX;//朝向向量的X分量，无需归一化
        qreal facingdirectionY;//朝向向量的Y分量，无需归一化
        virtual void setPosition(qreal x,qreal y,qreal facex,qreal facey);
        qreal facingXYtoAngle();
        QPixmap pixmap;
        QRect rect;
        QString type;
    };
}


#endif // FLYINGOBJECT_H
