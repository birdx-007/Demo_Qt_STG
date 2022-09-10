#include "enemy.h"
namespace stg
{
    Zako::Zako(qreal x,qreal y,int maxhp,qreal facex,qreal facey):Enemy(x,y,maxhp,facex,facey)
    {
        this->rect.setWidth(this->pixmap.width());
        this->rect.setHeight(this->pixmap.height());
        this->type=QString("zako");
    }
}
