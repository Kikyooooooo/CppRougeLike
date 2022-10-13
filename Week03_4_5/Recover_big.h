#pragma once
#include "Recover_small.h"
class Recover_big :
    public Recover_small
{
public:
    virtual void purchase(Pawn* _pawn, int amount) override;
    Recover_big();

};

