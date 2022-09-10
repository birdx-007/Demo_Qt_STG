QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auxiliarybullet.cpp \
    ball.cpp \
    boss.cpp \
    bullet.cpp \
    bulletmanager.cpp \
    danmakumanager.cpp \
    enemy.cpp \
    enemybullet.cpp \
    enemymanager.cpp \
    flyingobject.cpp \
    hero.cpp \
    main.cpp \
    mainbullet.cpp \
    managerdep.cpp \
    map.cpp \
    movevector.cpp \
    widget.cpp \
    zako.cpp

HEADERS += \
    bullet.h \
    bulletmanager.h \
    danmakumanager.h \
    enemy.h \
    enemymanager.h \
    flyingobject.h \
    hero.h \
    managerdep.h \
    map.h \
    movevector.h \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
