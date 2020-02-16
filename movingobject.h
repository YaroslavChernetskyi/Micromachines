#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "staticobject.h"
#include "moveable.h"
#include "collisionable.h"


class MovingObject: public StaticObject, public Moveable,public Collisionable
{
public:
    MovingObject(int angle, int x, int y);
    void move() override = 0;
    void coordinatesChanging()override;
    void collisionWithObject(StaticObject*)override;
    void collisionWithAbyss() override;
    void collisionWithFieldEnd() override;
    void jumpingZone(bool) override;
    void jump() override;
    int getAngle() override;
    bool finish() override;
    void saveCoordinates()override;

protected:
    int angle;
    double speed;
    double maxSpeed;
    double acceleration;
    double deceleration;
    int counterForFallingDown;
    int counterForCarMoving;
    int counterForSaving;
    int lastX,lastY;
    bool m_jumpingZone;
    bool kUp, kRight, kDown, kLeft, kNone;
};

#endif // MOVINGOBJECT_H
