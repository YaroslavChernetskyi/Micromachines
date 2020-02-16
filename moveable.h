#ifndef MOVEABLE_H
#define MOVEABLE_H
#include"staticobject.h"
#include<cmath>

class Moveable
{
public:
    virtual ~Moveable() = default;
    virtual void move() = 0;
    virtual void coordinatesChanging()= 0;
    virtual void jump() = 0;
    virtual int getAngle() = 0;
    virtual bool finish() = 0;
    virtual void saveCoordinates() = 0;

};
#endif // MOVEABLE_H
