#ifndef OPPONENTLEFT_H
#define OPPONENTLEFT_H
#include "opponentstate.h"

class OpponentLeft : public  OpponentState {
public:
    void next(Opponent *opponent) override final;
};

#endif // OPPONENTLEFT_H
