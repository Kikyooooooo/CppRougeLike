#include "Spear.h"
#include "Pawn.h"
#include "AI.h"
#include "AllMacro.h"

void Spear::PawnRound(Pawn* _pawn, AI* _ai)
{
    print("1.����");
    print("2.����");
   
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
            print("ѡ������");
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
    w_name = "��ǹ";

    strcpy_s(c_name, "��ǹ");
    commodify_index = 2;
    c_stock = 1;
    c_price = 40;
    strcpy_s(depict, "<����>�߹������߷����Ļ���������");

}
