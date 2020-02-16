#include "opponentup.h"
#include "opponentright.h"
#include "opponent.h"


void OpponentUp::next(Opponent *opponent) {
    opponent->setAngle(90);
    opponent->setState(new OpponentRight());
    delete this;
}

