#ifndef MANAGERDEP_H
#define MANAGERDEP_H

#include <QObject>
#include <QtMath>
#include <hero.h>
#include "bulletmanager.h"
#include "enemymanager.h"
#include "danmakumanager.h"
namespace stg
{
    class ManagerDep : public QObject
    {
        Q_OBJECT
    public:
        ManagerDep(QObject *parent = nullptr);
        Hero* hero;
        BulletManager bulletmanager;
        EnemyManager enemymanager;
        DanmakuManager danmakumanager;
        void SetHero(Hero *hero_);
        void ManageCollisions();
        void ManageHeroMainBulletsMoving();
        void ManageHeroAuxiliaryBulletsMoving();
        void ManageEnemyBulletsMoving();
        void DestoryInvalidObjects();
        void DestoryAllObjects();
        void GenerateSpellCard(int counter);
    signals:
    };
}


#endif // MANAGERDEP_H
