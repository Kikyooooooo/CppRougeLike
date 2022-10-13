#include "BlastProp.h"
#include "Monster.h"
#include "AllMacro.h"
#include "Pawn.h"

void BlastProp::Use(Monster* _monster)
{
	float tempDamage = _monster->m_HP * 0.2 + this->BlastDamage;
	_monster->GetHurt(tempDamage);//给伤害

	DEBUFF* temp = new DEBUFF(DEBUFFKind::Efiring, this->FiringCycle);
	_monster->AddBuff(temp);//给灼烧
}

void BlastProp::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(BlastProp)
}

BlastProp::BlastProp()
{
	BlastDamage = 50;
	FiringCycle = 5;

	strcpy_s(c_name, "爆炸弹");
	commodify_index = 7;
	c_stock = 1;
	c_price = 20;
	strcpy_s(depict, "<道具><仅可在战斗中使用>一次性爆炸伤害，附带灼烧效果。");


}


