#include "opponentdown.h"
#include "opponent.h"
#include "opponentleft.h"

void OpponentDown::next(Opponent *opponent) {
    opponent->setAngle(270);
    opponent->setState(new OpponentLeft());
    delete this;
}
