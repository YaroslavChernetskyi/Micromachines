#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include <QString>
#include "drawable.h"
#include "positional.h"

const int OBJECT_SIZE = 50;
const int FIELD_WIDTH = 30;
const int FIELD_HEIGHT = 18;

class StaticObject:public Positional, public Drawable
{

public:
    StaticObject(int, int);
    int getX() override final;
    int getY() override final;
    int getHeight() override final;
    int getWidth() override final;
    void setHighness(int) override final;
    void draw(QPainter *, int, int) override = 0;
    QRectF boundRect() override = 0;
protected:
    int width, height, highness;
    int x, y;
    QString img;

};

#endif // STATICOBJECT_H
