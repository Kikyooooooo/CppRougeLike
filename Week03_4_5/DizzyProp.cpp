#include "Pawn.h"
#include "DizzyProp.h"
#include "Monster.h"
#include "AllMacro.h"

void DizzyProp::Use(Monster* _monster)
{
	DEBUFF* temp = new DEBUFF(DEBUFFKind::Edizzy, this->DizzyCycles);
	_monster->AddBuff(temp);
}

void DizzyProp::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(DizzyProp)
}

DizzyProp::DizzyProp()
{
	DizzyCycles = 3;

	strcpy_s(c_name, "催眠弹");
	commodify_index = 6;
	c_stock = 1;
	c_price = 10;
	strcpy_s(depict, "<道具><仅可在战斗中使用>让敌方3回合无法行动。");
}
