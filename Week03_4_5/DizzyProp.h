#pragma once
#include "Commodify.h"
class DizzyProp :
    public Commodify
{
public:
    unsigned short DizzyCycles;
    virtual void Use(Monster* _monster) override;
    virtual void purchase(Pawn* _pawn, int amount) override;
       
    DizzyProp();
};

