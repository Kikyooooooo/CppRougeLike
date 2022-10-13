#pragma once
#include "Commodify.h"
class BlastProp :
    public Commodify
{
public:
    unsigned short BlastDamage;
    unsigned short FiringCycle;
    virtual void Use(Monster* _monster) override;
    virtual void purchase(Pawn* _pawn, int amount) override;

    BlastProp();
};

