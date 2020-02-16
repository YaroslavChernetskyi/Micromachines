#ifndef OPPONENTCARFACTORY_H
#define OPPONENTCARFACTORY_H

#include  "carfactory.h"

class OpponentCarFactory : public CarFactory
{
public:
    Opponent* createCar(int,int,int) override final;
};

#endif // OPPONENTCARFACTORY_H
