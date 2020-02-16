#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include "staticobject.h"

class Checkpoint: public StaticObject
{
public:
    Checkpoint(int,int);
    QRectF boundRect() override;
    void draw(QPainter *, int,int) override;
};

#endif // CHECKPOINT_H
