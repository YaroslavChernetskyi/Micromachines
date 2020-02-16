#ifndef MYCARFACTORY_H
#define MYCARFACTORY_H

#include  "carfactory.h"

class MyCarFactory : public CarFactory
{
public:
    Car *createCar(int,int,int) override final;
};

#endif // MYCARFACTORY_H
