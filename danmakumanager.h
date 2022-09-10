#ifndef DANMAKUMANAGER_H
#define DANMAKUMANAGER_H

#include <QObject>
#include <QtMath>
#include "bulletmanager.h"
#include "enemymanager.h"
namespace stg
{
    class DanmakuManager : public QObject
    {
        Q_OBJECT
    public:
        explicit DanmakuManager(QObject *parent = nullptr);
        BulletManager* bulletmanager;
        EnemyManager* enemymanager;
        void SetManagers(BulletManager* bm,EnemyManager* em);
        void AddOneCircle(qreal center_x,qreal center_y,int num_in_circle,QString type=QString("ball"),QString color=QString("red"));//环状弹幕
        void AddOneAim(FlyingObject *target,qreal init_x,qreal init_y,int num_of_line,qreal angle,QString type=QString("ball"),QString color=QString("red"));//自机狙
    signals:

    };
}


#endif // DANMAKUMANAGER_H
