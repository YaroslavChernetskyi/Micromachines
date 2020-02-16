#ifndef OPPONENTDOWN_H
#define OPPONENTDOWN_H
#include"opponentstate.h"

class OpponentDown : public OpponentState {
public:
    void next(Opponent *opponent) override final;
};

#endif // OPPONENTDOWN_H
