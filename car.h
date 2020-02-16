#ifndef CAR_H
#define CAR_H

#include"movingobject.h"
#include <QKeyEvent>


class Car: public MovingObject
{
public:
    Car(int angle, int x, int y);
    ~Car() override = default;
    void moveAfterPress(QKeyEvent *event);
    void moveAfterRelease(QKeyEvent *event);
    void draw(QPainter*, int,int) override final;
    void move() override final;
    QRectF boundRect()override;

};

#endif // CAR_H

