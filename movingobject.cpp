#include "movingobject.h"
#include <QDebug>
#define RADIAN 0.01745329

MovingObject::MovingObject(int angle, int x, int y):StaticObject (x,y)
{
    this->angle = angle;
    this->acceleration = 0.2;
    this->speed = 0;
    this->deceleration = 0.1;
    this->width = OBJECT_SIZE/2;
    this->height = OBJECT_SIZE/2;
    this->counterForFallingDown = 0;
    this->counterForCarMoving = 0;
    this->counterForSaving = 0;
    this->lastX = 0;
    this->lastY = 0;
    this->m_jumpingZone = false;
    this->highness = 0;

}

void MovingObject::collisionWithObject(StaticObject*)
{
    int ang = getAngle()%360;
    if(ang >= 180 || (ang<0&&ang>-180))
        ang-=180;
    else if ((ang>=0 && ang <180) || ang<=-180)
    {
        ang+=180;
    }
    x += ((sin(ang*RADIAN) *2*speed));
    y -= ((cos(ang*RADIAN) *2*speed));

    speed=0;
}

void MovingObject::collisionWithAbyss()
{
    if(highness==0)
    {
        speed = 0;
        counterForFallingDown++;
        kUp = 0; kRight = 0; kDown = 0; kLeft = 0; kNone = 0;
        if(counterForFallingDown == 2&&width>1)
        {
            width-=1;
            height-=1;
            counterForFallingDown=0;
        }
        if(counterForFallingDown==30)
        {
            x=lastX;
            y=lastY;
            width=OBJECT_SIZE/2;
            height = OBJECT_SIZE/2;
            counterForFallingDown=0;
        }
    }
}

void MovingObject::collisionWithFieldEnd()
{
    if(x<=0)
    {
        x+=3;
        speed=0;
    }
    else if(x >= 29*OBJECT_SIZE)
    {
        x-=3;
        speed=0;
    }
    if(y<=0)
    {
        y+=3;
        speed=0;
    }
    else if(y >= 17*OBJECT_SIZE)
    {
        y-=3;
        speed=0;
    }
}

void MovingObject::jumpingZone(bool n)
{
    m_jumpingZone = n;
}

void MovingObject::jump()
{
    if(m_jumpingZone&&speed>1.7&&lastX<18*OBJECT_SIZE-10)
    {
        highness=static_cast<int>(14.8*OBJECT_SIZE-x);
        if(x<15*OBJECT_SIZE)
        {
            highness = (x-12*OBJECT_SIZE)/10;
        }
        else
        {
            highness=((x-(18*OBJECT_SIZE-10))*(-1))/10;
        }
        width = OBJECT_SIZE/2 + (highness);
        height= OBJECT_SIZE/2 +(highness);
    }
    else
    {
        highness = 0;
    }
    saveCoordinates();
}


int MovingObject::getAngle()
{
    return angle;
}

bool MovingObject::finish()
{
    if(getX() > 2*OBJECT_SIZE && getX() < 6*OBJECT_SIZE &&
            getY() < 9*OBJECT_SIZE+10 && getY()>9*OBJECT_SIZE+1)
        return true;
    else return false;
}

void MovingObject::saveCoordinates()
{
    counterForSaving++;
    if(counterForSaving == 60)
    {
        if(m_jumpingZone||speed<1.7)
            counterForSaving = 0;
        else
        {
        lastX = x;
        lastY = y;
        counterForSaving = 0;
        }
    }
}

void MovingObject::coordinatesChanging()
{
    x += qRound((sin(angle*RADIAN) * speed));
    y -= qRound((cos(angle*RADIAN) * speed));
}

