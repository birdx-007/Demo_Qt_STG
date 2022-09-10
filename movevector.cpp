#include "movevector.h"
namespace stg
{
    MoveVector::MoveVector()
    {
        for(int i=0;i<5;i++)
        {
            this->StateofMoveKeys[i]=QString("unpressed");
        }
        this->toZeroVector();
    }

    void MoveVector::toZeroVector()
    {
        this->Vx=0;
        this->Vy=0;
    }

    void MoveVector::GenerateVector()
    {
        this->toZeroVector();
        if(this->StateofMoveKeys[0]==QString("pressed"))
        {
            this->AddVx(-1.0);
        }
        if(this->StateofMoveKeys[1]==QString("pressed"))
        {
            this->AddVy(-1.0);
        }
        if(this->StateofMoveKeys[2]==QString("pressed"))
        {
            this->AddVy(1.0);
        }
        if(this->StateofMoveKeys[3]==QString("pressed"))
        {
            this->AddVx(1.0);
        }
        qreal length=qSqrt(this->Vx*this->Vx+this->Vy*this->Vy);
        if(length!=qreal(0.0))
        {
            this->Vx=this->Vx/length;
            this->Vy=this->Vy/length;
        }
    }

    void MoveVector::AddVx(qreal deltax)
    {
        this->Vx+=deltax;
    }

    void MoveVector::AddVy(qreal deltay)
    {
        this->Vy+=deltay;
    }
}
