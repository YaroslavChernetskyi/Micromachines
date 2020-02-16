#ifndef ABYSS_H
#define ABYSS_H

#include "staticobject.h"
class Abyss: public StaticObject
{
public:
    Abyss(int,int);
    QRectF boundRect() override;
    void draw(QPainter *, int,int) override;
};

#endif // ABYSS_H
