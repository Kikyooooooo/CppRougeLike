#pragma once
#include "Weapon.h"
#include "Commodify.h"
class Torch :
    public Weapon, public Commodify
{
public:
    short firing_rate;
    virtual void PawnRound(Pawn* _pawn, AI* _ai);
    virtual post CauseDamage();
    virtual void Use(Pawn* _pawn)override;
    virtual void purchase(Pawn* _pawn, int amount) override;

    Torch();
};

