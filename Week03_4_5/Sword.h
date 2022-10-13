#pragma once
#include"Weapon.h"
#include"Commodify.h"

class Sword :
    public Weapon,public Commodify
{
private:
    int crit_proportion;//>1
    int blood_proportion;//0~1
public:
    int crit_rate;
    int blood_rate;
    int dizzy_rate;



    Sword();
    Sword( float _damage, int _hold_rate, int _blood_rate);

    virtual post CauseDamage() override;
    virtual void PawnRound(Pawn* _pawn, AI* _ai) override;

    //重写商品函数
    virtual void purchase(Pawn* _pawn, int amount) override;
    virtual void Use(Pawn* _pawn)override;
};

