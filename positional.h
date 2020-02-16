#ifndef POSITIONAL_H
#define POSITIONAL_H

#include <QRectF>
class Positional
{
public:
    virtual ~Positional() = default;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual int getHeight() = 0;
    virtual int getWidth() = 0;
    virtual void setHighness(int) = 0;
    virtual QRectF boundRect() = 0;
};

#endif // POSITIONAL_H
