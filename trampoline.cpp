#include "trampoline.h"

Trampoline::Trampoline(int x, int y):StaticObject (x,y)
{
    this->width = OBJECT_SIZE*(FIELD_WIDTH/15);
    this->height = OBJECT_SIZE*(FIELD_HEIGHT/9);
    this->img = ":/img/tr.png";
}

void Trampoline::draw(QPainter *painter, int camX, int camY)
{
    QPixmap pixmap(img);
    painter->drawPixmap(x-camX, y-camY, width, height, pixmap);
}

QRectF Trampoline::boundRect()
{
    return QRectF(x,y,6*OBJECT_SIZE-10,2*OBJECT_SIZE);
}
