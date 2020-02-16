#ifndef CARFACTORY_H
#define CARFACTORY_H

#include "movingobject.h"
#include "car.h"
#include "opponent.h"

class CarFactory {
public:
    virtual MovingObject* createCar(int,int,int) = 0;
    virtual ~CarFactory() = default;
};

#endif // CARFACTORY_H
