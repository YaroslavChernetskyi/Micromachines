#include "mycarfactory.h"

Car* MyCarFactory::createCar(int angle, int x, int y)
{
    return new Car(angle, x, y);
}
