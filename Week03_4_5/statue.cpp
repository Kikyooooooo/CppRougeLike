#include "statue.h"
#include"AllMacro.h"
#include"Pawn.h"

void statue::Use(Pawn* _pawn)
{
	statue* temp = new statue;
	_pawn->SetProps(temp);
}

void statue::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(statue)
}

statue::statue()
{
	commodify_index = 15;
	c_stock = 1;
	c_price = 70;
	strcpy_s(c_name, "掠夺浮雕");
	strcpy_s(depict, "<护符>击败敌人时，恢复敌人血量的20%。");
}
