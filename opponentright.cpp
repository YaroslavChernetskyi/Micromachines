#include "opponentright.h"
#include "opponent.h"
#include "opponentdown.h"

void OpponentRight::next(Opponent *opponent) {
    opponent->setAngle(180);
    opponent->setState(new OpponentDown());
    delete this;
}
