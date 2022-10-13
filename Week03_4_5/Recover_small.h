#pragma once
#include "Commodify.h"
class Recover_small :
    public Commodify
{
public:
    unsigned short RecoverAmount;
    virtual void Use(Pawn* _pawn) override;
    virtual void purchase(Pawn* _pawn, int amount) override;

    Recover_small();
};

