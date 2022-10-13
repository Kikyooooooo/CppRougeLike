#include "AlmightProp.h"
#include "Monster.h"
#include "AllMacro.h"
#include "Pawn.h"

void AlmightProp::Use(Pawn* _pawn)
{
	_pawn->Max_HP += AddAmount;
	_pawn->p_HP = _pawn->Max_HP;
}

void AlmightProp::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(AlmightProp)
}

AlmightProp::AlmightProp()
{
	AddAmount = 30;

	strcpy_s(c_name, "��ҩ");
	commodify_index = 11;
	c_stock = 1;
	c_price = 50;
	strcpy_s(depict, "<����>����Ѫ�����޲��һָ�����Ѫ��");

}
