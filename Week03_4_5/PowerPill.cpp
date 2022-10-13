#include "PowerPill.h"
#include "Pawn.h"
#include "AllMacro.h"

void PowerPill::Use(Pawn* _pawn)
{
	playerState* temp = new playerState(state::EPower, this->Power_cycle);
	_pawn->AddBuff(temp);

}

void PowerPill::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(PowerPill)
}

PowerPill::PowerPill()
{
	Power_cycle = 3;

	strcpy_s(c_name, "怪力药丸");
	commodify_index = 8;
	c_stock = 1;
	c_price = 15;
	strcpy_s(depict, "<道具><仅可在战斗中使用>3回合内，攻击力加强。");

}
