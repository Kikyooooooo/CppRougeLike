#include "Sword.h"
#include "Weapon.h"
#include "Pawn.h"
#include "AllMacro.h"
using namespace std;
//Ĭ�ϲ���
Sword::Sword()
{
	this->base_damage = 100.0f;
	this->crit_rate = 30;
	this->crit_proportion = 2;
	this->blood_rate = 30;
	this->blood_proportion = 0.5;
	this->dizzy_rate = 15;
	w_name = "��ԯ��";

	c_stock = 1;
	c_price = 300;
	commodify_index = 4;
	strcpy_s(c_name, "��ԯ��");
	strcpy_s(depict, "<����>ÿһ�ι������и��ʲ�����Ѫ��������ѣ�ε���Ч��");
}



Sword::Sword(float _damage, int crit_rate, int _blood_rate):crit_rate(crit_rate),blood_rate(_blood_rate)
{
	this->blood_proportion = 0.5;
	this->crit_proportion = 2;
	this->dizzy_rate = 15;
	this->base_damage = _damage;
}


post Sword::CauseDamage()
{
	post ReturnValue;
	const bool dizzy = this->GetBoolForRate(dizzy_rate);
	const bool suckBlood = this->GetBoolForRate(blood_rate);
	const bool crit = this->GetBoolForRate(dizzy_rate);

	float damage = 0.0f;
	float suckValue = 0.0f;


	//�����˺�����Ѫֵ
	if (crit == true) {
		damage = (this->base_damage+_RANDFORRANGE(-5, 5)) * crit_proportion;
	}
	else
	{
		damage = this->base_damage + _RANDFORRANGE(-5,5);//�˺�����
	}

	if (suckBlood == true) suckValue = damage * blood_proportion;


	//ƴװ����ֵ
	ReturnValue.IsDizzy = dizzy;
	ReturnValue.IsCrit = crit;
	ReturnValue.CauseDamage = damage;
	ReturnValue.Suckblood = suckValue;

	
	return ReturnValue;
}

void Sword::PawnRound(Pawn* _pawn, AI* _ai) {

	print("1.����");
	print("2.����");

	while (true)
	{
		_GETCHOOSE;
		switch (choose)
		{
		case 1:
			_pawn->Attack(_ai);
			return;
		case 2:
			_pawn->AddBuff(EPlayerState::Edefense);
			return;
		default:
			print("ѡ������");
			continue;
		}
	}

}

void Sword::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(Sword)

}


void Sword::Use(Pawn* _pawn)
{ 
	_MODIFYUSEFORWEAPON(Sword)
}