#include "LessHPAddDamage.h"
#include"AllMacro.h"
#include"Pawn.h"

void LessHPAddDamage::Use(Pawn* _pawn)
{
	LessHPAddDamage* temp = new LessHPAddDamage;
	_pawn->SetProps(temp);
}

void LessHPAddDamage::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(LessHPAddDamage)
}

LessHPAddDamage::LessHPAddDamage()
{
	commodify_index = 3;
	c_stock = 1;
	c_price = 100;
	strcpy_s(c_name, "七刃剑");
	strcpy_s(depict, "<护符>血量低于50%时，增加伤害。");
}
