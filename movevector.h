#ifndef MOVEVECTOR_H
#define MOVEVECTOR_H

#include <QtMath>
#include <QString>
#include "flyingobject.h"
namespace stg
{
    class MoveVector
    {
    public:
        MoveVector();
        void toZeroVector();
        void GenerateVector();
        void AddVx(qreal deltax);
        void AddVy(qreal deltay);
        QString StateofMoveKeys[5];
        qreal Vx;
        qreal Vy;
    };
}
#endif // MOVEVECTOR_H
