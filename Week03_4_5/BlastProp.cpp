#include "BlastProp.h"
#include "Monster.h"
#include "AllMacro.h"
#include "Pawn.h"

void BlastProp::Use(Monster* _monster)
{
	float tempDamage = _monster->m_HP * 0.2 + this->BlastDamage;
	_monster->GetHurt(tempDamage);//���˺�

	DEBUFF* temp = new DEBUFF(DEBUFFKind::Efiring, this->FiringCycle);
	_monster->AddBuff(temp);//������
}

void BlastProp::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(BlastProp)
}

BlastProp::BlastProp()
{
	BlastDamage = 50;
	FiringCycle = 5;

	strcpy_s(c_name, "��ը��");
	commodify_index = 7;
	c_stock = 1;
	c_price = 20;
	strcpy_s(depict, "<����><������ս����ʹ��>һ���Ա�ը�˺�����������Ч����");


}


