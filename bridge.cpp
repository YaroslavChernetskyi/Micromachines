#include "bridge.h"

Bridge::Bridge(int x, int y):StaticObject (x,y)
{
    this->width = OBJECT_SIZE*(FIELD_WIDTH/10);
    this->height = OBJECT_SIZE*(FIELD_HEIGHT/9);
    this->img = ":/img/bridge.png";
}

QRectF Bridge::boundRect()
{
    return QRectF(this->x,this->y+OBJECT_SIZE/2,width, height-OBJECT_SIZE/2);
}

void Bridge::draw(QPainter * painter, int camX, int camY)
{
    QPixmap pixmap(img);
    painter->drawPixmap(x-camX, y-camY, width, height, pixmap);
}
