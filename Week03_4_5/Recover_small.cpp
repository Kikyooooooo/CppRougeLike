#include "Recover_small.h"
#include "Pawn.h"
#include "AllMacro.h"

void Recover_small::Use(Pawn* _pawn)
{
	_pawn->p_HP += this->RecoverAmount;

}

void Recover_small::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(Recover_small)
}

Recover_small::Recover_small()
{
	this->RecoverAmount = 30;

	strcpy_s(c_name, "回复药(小)");
	commodify_index = 9;
	c_stock = 1;
	c_price = 20;
	strcpy_s(depict, "<道具>恢复30点血量。");


}


