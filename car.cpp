#include "car.h"
#include "opponent.h"
#include<QtMath>
#include<QDebug>
#include"math.h"
#include<QBitmap>

Car::Car(int angle, int x, int y):MovingObject (angle,x,y)
{
    this->maxSpeed = 5;
    this->counterForCarMoving = 0;
    kUp = 0; kRight = 0; kDown = 0; kLeft = 0; kNone = 0;
}


void Car::moveAfterPress(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
        kLeft = 1;
        break;
    case Qt::Key_Right:
        kRight=1;
        break;
    case Qt::Key_Up:
        kNone =0;
        kUp=1;
        break;
    case Qt::Key_Down:
        kNone = 0;
        kDown=1;
        break;
    }
}

void Car::moveAfterRelease(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Left:
            kLeft = 0;
            break;
        case Qt::Key_Right:
            kRight=0;
            break;
        case Qt::Key_Up:
            kNone =1;
            kUp=0;
            break;
        case Qt::Key_Down:
            kNone =1;
            kDown=0;
            break;
    }
}

QRectF Car::boundRect()
{
    return QRectF(this->x,this->y,OBJECT_SIZE/2, OBJECT_SIZE/2);
}

void Car::draw(QPainter *painter, int camX, int camY)
{
    int rotAngle = static_cast<int>( fmod(this->angle,360.0));
    QString valueAsString = QString::number(rotAngle>=0?rotAngle:(rotAngle+360));
    this->img = ":/img/car" + valueAsString + ".png";
    QPixmap pixmap(img);
    painter->drawPixmap(x-camX, y-camY, width, height, pixmap);

}


void Car::move()
{
    collisionWithFieldEnd();
    if(kUp)
    {
        if (speed<maxSpeed)
        {
            if (speed < 0)
            {
                speed += deceleration;
            }
            else
            {
                speed += acceleration;
            }
        }
        coordinatesChanging();
    }
    else if(kDown)
    {
        if ( speed>-maxSpeed)
        {
            if (speed > 0)
            {
                speed -= deceleration;
            }
            else
            {
                speed -= acceleration;
            }
        }
        coordinatesChanging();
    }
    else if(kNone)
    {
        if (speed - deceleration > 0) speed -= deceleration;
        else if (speed + deceleration < 0) speed += deceleration;
        else speed = 0;
        coordinatesChanging();
    }
    if(kLeft)
    {
        counterForCarMoving++;
        if(counterForCarMoving == 4)
        {
            angle -= 10;
            counterForCarMoving = 0;
        }
    }
    if(kRight)
    {
        counterForCarMoving++;
        if(counterForCarMoving == 4)
        {
            angle += 10;
            counterForCarMoving=0;
        }
    }
}
