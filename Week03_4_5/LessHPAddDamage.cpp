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
	strcpy_s(c_name, "���н�");
	strcpy_s(depict, "<����>Ѫ������50%ʱ�������˺���");
}
