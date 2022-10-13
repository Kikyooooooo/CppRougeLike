#include "Torch.h"
#include "Pawn.h"
#include "AI.h"

#include "AllMacro.h"

void Torch::PawnRound(Pawn* _pawn, AI* _ai)
{
    print("1.攻击");
    print("2.防御");
  
    while (true) {
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
            print("选择有误！");
            continue;
        }
    }


}

post Torch::CauseDamage()
{
    const bool IsFiring = GetBoolForRate(firing_rate);
    const float damage = base_damage + _RANDFORRANGE(-3, 3);
    post ReturnValue;
    ReturnValue.CauseDamage = damage;
    ReturnValue.IsFiring = IsFiring;
    return ReturnValue;
}

void Torch::Use(Pawn* _pawn)
{
    _MODIFYUSEFORWEAPON(Torch)
}

void Torch::purchase(Pawn* _pawn, int amount)
{
    _PURCHASE(Torch)
        
}


Torch::Torch()
{
    base_damage = 15;
    FiringDamage = 5;
    firing_rate = 35;
    w_name = "火把";

    strcpy_s(c_name, "火把");
    strcpy_s(depict, "<武器>攻击有概率触发灼烧特效。");
    commodify_index = 1;
    c_stock = 1;
    c_price = 30;
}
