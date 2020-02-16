#include "opponentleft.h"
#include "opponent.h"
#include "opponentup.h"

void OpponentLeft::next(Opponent *opponent) {
    opponent->setAngle(0);
    opponent->setState(new OpponentUp());
    delete this;
}
