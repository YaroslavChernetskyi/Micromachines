#include "staticobject.h"

StaticObject::StaticObject(int x, int y):
    x(x),
    y(y)
{

}

int StaticObject::getX()
{
    return x;
}

int StaticObject::getY()
{
    return y;
}

int StaticObject::getHeight()
{
    return height;
}

int StaticObject::getWidth()
{
    return width;
}

void StaticObject::setHighness(int h)
{
    highness = h;
}


