#include "Spear.h"
#include "Pawn.h"
#include "AI.h"
#include "AllMacro.h"

void Spear::PawnRound(Pawn* _pawn, AI* _ai)
{
    print("1.¹¥»÷");
    print("2.·ÀÓù");
   
    while (true)
    {
        _GETCHOOSE;
        switch (choose)
        {
        case 1:
            _pawn->Attack(_ai);
            return;
        case 2:
            _pawn->AddBuff(EPlayerState::Edefense);
            return;
        default:
            print("Ñ¡ÔñÓÐÎó£¡");
            continue;
        }
    }
}

post Spear::CauseDamage()
{
    const float damage = base_damage + _RANDFORRANGE(-3, 3);
    post ReturnValue;
    ReturnValue.CauseDamage = damage;
    return ReturnValue;
}

void Spear::Use(Pawn* _pawn)
{
    _MODIFYUSEFORWEAPON(Spear)
}

void Spear::purchase(Pawn* _pawn, int amount)
{
    _PURCHASE(Spear)
}

Spear::Spear()
{
    base_damage = 30;
    base_defense = 0.7;
    w_name = "³¤Ç¹";

    strcpy_s(c_name, "³¤Ç¹");
    commodify_index = 2;
    c_stock = 1;
    c_price = 40;
    strcpy_s(depict, "<ÎäÆ÷>¸ß¹¥»÷¡¢¸ß·ÀÓùµÄ»ù´¡ÎäÆ÷¡£");

}
