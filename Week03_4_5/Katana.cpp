#include "Katana.h"
#include"Pawn.h"
#include"AI.h"

#include"AllMacro.h"

void Katana::PawnRound(Pawn* _pawn, AI* _ai)
{
	print("1.����");
	
    while (true) {
        _GETCHOOSE;
        switch (choose)
        {
        case 1:
            _pawn->Attack(_ai);
            return;
        default:
            print("ѡ������");
            continue;
        }
    }
}

post Katana::CauseDamage()
{
    post ReturnValue;
    const bool IsCrit = GetBoolForRate(crit_rate);
    float damage = this->base_damage;
    if (IsCrit) damage *= crit_proportion;
    ReturnValue.CauseDamage = damage;
    ReturnValue.IsCrit = IsCrit;
	return ReturnValue;
}

void Katana::Use(Pawn* _pawn)
{
    _MODIFYUSEFORWEAPON(Katana)
}

void Katana::purchase(Pawn* _pawn, int amount)
{
    _PURCHASE(Katana)
}

Katana::Katana()
{
    base_damage = 40;
    crit_rate = 50;
    crit_proportion = 2.3;
    w_name = "̫��";


    commodify_index = 3;
    c_stock = 1;
    c_price = 100;
    strcpy_s(c_name, "̫��");
    strcpy_s(depict, "<����>�������ߡ������ʸߡ������˺��ߣ����ǲ��ܷ�����");

}
