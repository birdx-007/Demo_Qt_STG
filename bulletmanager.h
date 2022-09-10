#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H
#include <QObject>
#include <QtMath>
#include <vector>
#include <iterator>
#include <QString>
#include "bullet.h"
#include "flyingobject.h"
namespace stg
{
    class BulletManager : public QObject
    {
        Q_OBJECT
    public:
        explicit BulletManager(QObject *parent = nullptr);
        std::vector<Bullet> herobullets;
        std::vector<EnemyBullet> enemybullets;
        void AddOneHeroBullet(QString type,int x,int y);
        void AddOneBall(qreal x,qreal y,qreal facex,qreal facey,QString flytype,QString color);
        void MoveOneHeroMainBullet(Bullet *bullet);
        void MoveOneAuxiliaryBullet(Bullet *bullet,FlyingObject *target);
        void MoveOneEnemyBullet(EnemyBullet *bullet,FlyingObject *target=NULL);
        void DestoryInvalidBullets();
        void DestoryAllEnemyBullets();
    signals:

    };
}

#endif // BULLETMANAGER_H
