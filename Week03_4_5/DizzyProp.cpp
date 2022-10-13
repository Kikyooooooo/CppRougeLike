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

	strcpy_s(c_name, "���ߵ�");
	commodify_index = 6;
	c_stock = 1;
	c_price = 10;
	strcpy_s(depict, "<����><������ս����ʹ��>�õз�3�غ��޷��ж���");
}
