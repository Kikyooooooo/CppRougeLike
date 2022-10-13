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

	strcpy_s(c_name, "����ҩ��");
	commodify_index = 8;
	c_stock = 1;
	c_price = 15;
	strcpy_s(depict, "<����><������ս����ʹ��>3�غ��ڣ���������ǿ��");

}
