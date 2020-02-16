#include "abyss.h"

Abyss::Abyss(int x, int y):StaticObject (x,y)
{
    this->width = OBJECT_SIZE*(FIELD_WIDTH/10);
    this->height = OBJECT_SIZE*FIELD_HEIGHT;
    this->img = ":/img/prirva.png";
}

QRectF Abyss::boundRect()
{
    return QRectF(this->x+OBJECT_SIZE/2,this->y,width-OBJECT_SIZE/2, height);
}

void Abyss::draw(QPainter * painter, int camX, int camY)
{
    QPixmap pixmap(img);
    painter->drawPixmap(x-camX, y-camY, width, height, pixmap);
}

