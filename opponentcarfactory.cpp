#include "opponentcarfactory.h"

Opponent *OpponentCarFactory::createCar(int angle, int x, int y)
{
    return new Opponent(angle, x, y);
}
