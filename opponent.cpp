#include "opponent.h"
#include "opponentup.h"
#include<QDebug>
#include "game.h"
#include<QBitmap>

Opponent::Opponent(int angle, int x, int y):MovingObject(angle,x,y)
{
    this->counterForCarMoving = 0;
    this->maxSpeed = 3.5;
    this->state = new OpponentUp();
    mUp = 1;
}

void Opponent::draw(QPainter *painter, int camX, int camY)
{
    double rotAngle = fmod(angle,360.0);
    QString valueAsString = QString::number(rotAngle>0?rotAngle:(-1*rotAngle));
    this->img = ":/img/op_car" + valueAsString + ".png";
    QPixmap pixmap(img);
    painter->drawPixmap(x-camX, y-camY, width, height, pixmap);
}

QRectF Opponent::boundRect()
{
    return QRectF(x,y,width, height);
}

void Opponent::move()
{
    collisionWithFieldEnd();
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

void Opponent::setState(OpponentState *s) {
    this->state = s;
}

void Opponent::changeState() {
    this->state->next(this);
}

void Opponent::changeAngle()
{
        if((getY() <= 4*OBJECT_SIZE)&&mUp)
        {
            state->next(this);
            mUp=0;mRight=1;
        }
        else if(getX() > 25*OBJECT_SIZE&&mRight)
        {
            state->next(this);
            mRight=0;mDown=1;
        }
        else if(getY() > 14*OBJECT_SIZE&&mDown)
        {
          state->next(this);
          mDown=0;mLeft=1;
        }
        else if(getX() < 3*OBJECT_SIZE&&mLeft)
        {
            state->next(this);
            mLeft=0;mUp=1;
        }

    }

void Opponent::setAngle(int a)
{
    angle = a;
}

