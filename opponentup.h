#ifndef OPPONENTUP_H
#define OPPONENTUP_H
#include"opponentstate.h"

class OpponentUp : public  OpponentState {
public:
    void next(Opponent *opponent) override final;
};

#endif // OPPONENTUP_H
