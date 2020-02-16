#include "checkpoint.h"
#include "QDebug"

Checkpoint::Checkpoint(int x, int y):StaticObject(x,y)
{
    this->width = OBJECT_SIZE;
    this->height = OBJECT_SIZE;
    this->img = ":/img/ball1.gif";
}

QRectF Checkpoint::boundRect()
{
    return QRectF(x+3,y+3,width-6, height-6);
}

void Checkpoint::draw(QPainter * painter, int camX, int camY)
{
    QPixmap pixmap(img);
    //qDebug()<<camX;
    painter->drawPixmap(x-camX, y-camY, width, height, pixmap);
}
