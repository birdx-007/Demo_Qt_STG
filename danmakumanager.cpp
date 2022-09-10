#include "danmakumanager.h"
namespace stg
{
    DanmakuManager::DanmakuManager(QObject *parent) : QObject(parent)
    {

    }

    void DanmakuManager::SetManagers(BulletManager *bm, EnemyManager *em)
    {
        this->bulletmanager=bm;
        this->enemymanager=em;
    }

    void DanmakuManager::AddOneCircle(qreal center_x, qreal center_y, int num_in_circle, QString type, QString color)
    {
        for(int i=0;i<num_in_circle;i++)
        {
            qreal piece=2*M_PI/num_in_circle;
            if(num_in_circle%2==0)
            {
                Q_UNUSED(color);
                if(type==QString("ball"))
                {
                    QString color1=(i%2==0)?QString("red"):QString("blue");
                    this->bulletmanager->AddOneBall(center_x,center_y,qCos(piece*i),qSin(piece*i),QString("line"),color1);
                }
            }
            else
            {
                if(type==QString("ball"))
                {
                    this->bulletmanager->AddOneBall(center_x,center_y,qCos(piece*i),qSin(piece*i),QString("line"),color);
                }
            }
        }
    }
    //angle:自机狙复数弹最外两条弹道的夹角
    void DanmakuManager::AddOneAim(FlyingObject *target, qreal init_x, qreal init_y, int num_of_line, qreal angle, QString type, QString color)
    {
        qreal targetx=target->X,targety=target->Y;
        qreal deltax=targetx-init_x,deltay=targety-init_y;
        qreal center_angle=qAtan2(deltay,deltax);
        qreal anglepiece=0;
        qreal initangle=center_angle;
        if(num_of_line>1)
        {
            anglepiece=angle/(num_of_line-1);
            initangle=center_angle-angle/2;
        }
        for(int i=0;i<num_of_line;i++)
        {
            qreal targetangle=initangle+i*anglepiece;
            if(type==QString("ball"))
            {
                this->bulletmanager->AddOneBall(init_x,init_y,qCos(targetangle),qSin(targetangle),QString("line"),color);
            }
        }
    }
}
