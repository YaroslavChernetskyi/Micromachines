#ifndef OPPONENT_H
#define OPPONENT_H

#include "car.h"
#include "opponentstate.h"

class Opponent: public MovingObject
{
    OpponentState *state;
    bool mUp,mRight,mLeft,mDown;
    void changeState();

public:
    Opponent(int angle, int x, int y);
    void changeAngle();
    void setAngle(int);
    void move() override;
    void draw(QPainter*, int,int) override;
    QRectF boundRect() override;
    void setState(OpponentState *s);
};

#endif // OPPONENT_H


