#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H

#include"staticobject.h"

class Collisionable
{
public:
    virtual ~Collisionable() = default;
    virtual void collisionWithObject(StaticObject*) = 0;
    virtual void collisionWithAbyss() = 0;
    virtual void collisionWithFieldEnd() = 0;
    virtual void jumpingZone(bool) = 0;

};
#endif // COLLISIONABLE_H
