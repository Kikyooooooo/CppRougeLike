#pragma once
#include "Commodify.h"
class AlmightProp :
    public Commodify
{
public:
    unsigned short AddAmount;

    virtual void Use(Pawn* _pawn) override;
    virtual void purchase(Pawn* _pawn, int amount) override;
    AlmightProp();
};

