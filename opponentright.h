#ifndef OPPONENTRIGHT_H
#define OPPONENTRIGHT_H
#include"opponentstate.h"

class OpponentRight : public OpponentState {
public:
    void next(Opponent *opponent) override final;
};
#endif // OPPONENTRIGHT_H
