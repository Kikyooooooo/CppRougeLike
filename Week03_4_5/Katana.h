#pragma once
#include"Commodify.h"
#include "Weapon.h"
class Katana :
    public Weapon,public Commodify
{
private:
    short crit_rate;
    short crit_proportion;
public:
    virtual void PawnRound(Pawn* _pawn, AI* _ai);
    virtual post CauseDamage();
    virtual void Use(Pawn* _pawn)override;
    virtual void purchase(Pawn* _pawn, int amount) override;
    Katana();
};

