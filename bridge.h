#ifndef BRIDGE_H
#define BRIDGE_H
#include "staticobject.h"

class Bridge:public StaticObject
{
public:
    Bridge(int,int);
    QRectF boundRect() override;
    void draw(QPainter *, int,int) override;
};

#endif // BRIDGE_H
