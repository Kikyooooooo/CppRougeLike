#pragma once
#include "Commodify.h"
class statue :
    public Commodify
{
public:
    virtual void Use(Pawn* _pawn) override;
    virtual void purchase(Pawn* _pawn, int amount) override;

    statue();
};

