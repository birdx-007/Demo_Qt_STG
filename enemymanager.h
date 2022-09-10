#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <QObject>
#include <QtMath>
#include <vector>
#include <iterator>
#include <QString>
#include "enemy.h"
#include "flyingobject.h"
namespace stg
{
    class EnemyManager : public QObject
    {
        Q_OBJECT
    public:
        explicit EnemyManager(QObject *parent = nullptr);
        std::vector<Boss> bosses;
        std::vector<Zako> zakos;
        void AddOneBoss(int maxhp,qreal x,qreal y);
        void MoveBoss(int counter);
        void DestoryInvalidBosses();
        void DestoryAllBosses();
    signals:

    };
}

#endif // ENEMYMANAGER_H
