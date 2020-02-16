#ifndef OPPONENTSTATE_H
#define OPPONENTSTATE_H

class Opponent;
class OpponentState
{
public:
    virtual void next(Opponent * )=0;
    virtual ~OpponentState() = default;
};

#endif // OPPONENTSTATE_H
