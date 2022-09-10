#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include "map.h"
#include "hero.h"
#include "movevector.h"
#include "bullet.h"
#include "bulletmanager.h"
#include "enemy.h"
#include "enemymanager.h"
#include "flyingobject.h"
#include "managerdep.h"
namespace stg
{
    class Widget : public QWidget
    {
        Q_OBJECT

    public:
        Widget(QWidget *parent = nullptr);
        ~Widget();
        void initScene();
        QTimer m_Timer;
        int counter;
        void playGame();
        void updateAllPosition();
        void paintEvent(QPaintEvent*event);
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);
        Map m_map;
        Hero m_hero;
        MoveVector m_vector;
        ManagerDep m_managerDep;
    };
}
#endif // WIDGET_H
