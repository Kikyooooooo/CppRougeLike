#pragma once
#include "Commodify.h"
class PowerPill :
    public Commodify
{
public:
    int Power_cycle;
    virtual void Use(Pawn* _pawn) override;
    virtual void purchase(Pawn* _pawn, int amount) override;

    PowerPill();
};

