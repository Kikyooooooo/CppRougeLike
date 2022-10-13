#include "Wand.h"
#include "Weapon.h"
#include "Pawn.h"
#include "AI.h"

#include "AllMacro.h"

using namespace std;
Wand::Wand()
{
	recoverAmount = 30;
	firingAmount = 2;
	frostAmount = 2;

	firingContinueAmount = 3;
	frostContinueAmount = 2;
	w_name = "������";

	base_damage = 60;

	this->FiringDamage = 25;

	strcpy_s(c_name, "������");
	c_stock = 1;
	c_price = 300;
	commodify_index = 5;
	strcpy_s(depict, "<����>ӵ�б��������ա��ָ����ܵĸ߼����ȡ�");

}


post Wand::CauseDamage()
{
	post ReturnValue;
	ReturnValue.CauseDamage = this->base_damage + _RANDFORRANGE(-3, 3);
	ReturnValue.IsCrit = false;
	ReturnValue.IsDizzy = false;
	ReturnValue.Suckblood = 0;

	
	return ReturnValue;
}

void Wand::PawnRound(Pawn* _pawn, AI* _ai)
{
	print("1.����");
	print("2.����");
	print("3.����");
	print("4.����");
	print("5.�ָ�Ѫ��");
	

	while (true) {
		_GETCHOOSE;

		switch (choose) {
		case 1:
			_pawn->Attack(_ai);
			return;
		case 2:
			_pawn->AddBuff(EPlayerState::Edefense);
			return;
		case 3:
			_ai->AddBuff(DEBUFFKind::Efrost);
			return;
		case 4:
			_ai->AddBuff(DEBUFFKind::Efiring);
			return;
		case 5:
			_pawn->p_HP += this->recoverAmount;
			cout << "�ָ���" << recoverAmount << "��Ѫ��" << endl;
			return;
			




		}

	}
}

void Wand::purchase(Pawn* _pawn,int amount)
{
	_PURCHASE(Wand)
}
void Wand::Use(Pawn* _pawn)
{
	_MODIFYUSEFORWEAPON(Wand);
}

