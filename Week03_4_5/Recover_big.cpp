#include "Recover_big.h"
#include "AllMacro.h"
#include "Pawn.h"


void Recover_big::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(Recover_big)
}

Recover_big::Recover_big()
{
	this->RecoverAmount = 50;

	strcpy_s(c_name, "�ظ�ҩ(��)");
	commodify_index = 10;
	c_stock = 1;
	c_price = 30;
	strcpy_s(depict, "<����>�ָ�50��Ѫ����");
}
