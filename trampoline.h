#ifndef SPRINGBOARD_H
#define SPRINGBOARD_H

#include"staticobject.h"

class Trampoline:public StaticObject
{
public:
    Trampoline(int,int);
    QRectF boundRect() override;
    void draw(QPainter *, int,int) override;
};

#endif // SPRINGBOARD_H
