#pragma once
#include "Weapon.h"
#include "Commodify.h"
class Wand :
    public Weapon, public Commodify
{
    short recoverAmount;
    short firingAmount;
    short frostAmount;
    
    short firingContinueAmount;
    short frostContinueAmount;

public:
    virtual post CauseDamage();
    virtual void PawnRound(Pawn* _pawn, AI* _ai) override;

    virtual void purchase(Pawn* _pawn, int amount) override;
    virtual void Use(Pawn* _pawn)override;
    Wand();

};

