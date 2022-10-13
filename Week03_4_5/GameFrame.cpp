//����character
#include "GameFrame.h"
#include "Pawn.h"
#include "Monster.h"
#include "AI.h"
//��������
#include "Weapon.h"
#include "Sword.h"
#include "Wand.h"
#include "Torch.h"
#include "Spear.h"
#include "Katana.h"
#include "DizzyProp.h"
#include "BlastProp.h"
#include "PowerPill.h"
#include "Recover_small.h"
#include "Recover_big.h"
#include "AlmightProp.h"
#include "AntidoteProp.h"
#include "ImpressProp.h"
#include "LessHPAddDamage.h"
#include "statue.h"

//����
#include <Windows.h>
#include "AllMacro.h"


GameFrame::GameFrame()
{
	this->now = GameState::EMainMenu;
	this->AttackCycleAmount = 1;
	this->AttackSuccesAmout = 0;

	_LOADCOMMODIFY(0, Torch,1);
	_LOADCOMMODIFY(1, Spear,1);
	_LOADCOMMODIFY(2, Katana,1);
	_LOADCOMMODIFY(3, Sword,1);
	_LOADCOMMODIFY(4, Wand,1);
	_LOADCOMMODIFY(5, DizzyProp,15);
	_LOADCOMMODIFY(6, BlastProp, 15);
	_LOADCOMMODIFY(7, PowerPill, 15);
	_LOADCOMMODIFY(8, Recover_small, 15);
	_LOADCOMMODIFY(9, Recover_big, 15);
	_LOADCOMMODIFY(10, AlmightProp, 15);
	_LOADCOMMODIFY(11, AntidoteProp, 15);
	_LOADCOMMODIFY(12, ImpressProp, 1);
	_LOADCOMMODIFY(13, LessHPAddDamage, 1);
	_LOADCOMMODIFY(14, statue, 1);


}




void GameFrame::MainMenu(Pawn* _pawn)
{
	system("cls");
	//now = MainMenu;
	cout << "��ǰλ�ڵ���" << this->AttackSuccesAmout << "��"<<endl;
	print("1.��ʼս��");
	print("2.�����̵�");
	print("3.������Ϣ");
	_GETCHOOSE;
	switch (choose) {
	case 1:
		if (!_pawn->weapon_ptr) { print("�㻹ûװ���������޷�ս����"); system("pause"); break; }//�п�
		system("cls");
		this->Attack(_pawn);
		break;
	case 2:
		this->ArmsStore(_pawn);
		break;
	case 3:
		_pawn->CheckPersonInfo();
		break;
	}

	//����ʱ�Լ����Լ� ��֤��������ϵͳ
	this->MainMenu(_pawn);
}

void GameFrame::ArmsStore(Pawn* _pawn)
{
	while (true)
	{
	system("cls");
	print("1.���");
	print("2.��ǹ");
	print("3.̫��");
	print("4.��ԯ��");
	print("5.������");
	print("6.���ߵ�");
	print("7.���Ƶ�");
	print("8.����ҩ��");
	print("9.�ظ�ҩ(С)");
	print("10.�ظ�ҩ����");
	print("11.��ҩ");
	print("12.��ҩ");
	print("13.��ӡ");
	print("14.���н�");
	print("15.�Ӷḡ��");
	print("---------------------------");
	std::cout << "��ǰ��ң�" << _pawn->balance <<std::endl;
	print("(����0����)");
		_GETCHOOSE;
		switch (choose)
		{
		case 1:
			PrintInfoAndCount(_pawn, AllCommodify[0]);
			break;
		case 2:
			PrintInfoAndCount(_pawn, AllCommodify[1]);
			break;
		case 3:
			PrintInfoAndCount(_pawn, AllCommodify[2]);
			break;
		case 4:
			PrintInfoAndCount(_pawn, AllCommodify[3]);
			break;
		case 5:
			PrintInfoAndCount(_pawn, AllCommodify[4]);
			break;
		case 6:
			PrintInfoAndCount(_pawn, AllCommodify[5]);
			break;
		case 7:
			PrintInfoAndCount(_pawn, AllCommodify[6]);
			break;
		case 8:
			PrintInfoAndCount(_pawn, AllCommodify[7]);
			break;
		case 9:
			PrintInfoAndCount(_pawn, AllCommodify[8]);
			break;
		case 10:
			PrintInfoAndCount(_pawn, AllCommodify[9]);
			break;
		case 11:
			PrintInfoAndCount(_pawn, AllCommodify[10]);
			break;
		case 12:
			PrintInfoAndCount(_pawn, AllCommodify[11]);
			break;
		case 13:
			PrintInfoAndCount(_pawn, AllCommodify[12]);
			break;
		case 14:
			PrintInfoAndCount(_pawn, AllCommodify[13]);
			break;
		case 15:
			PrintInfoAndCount(_pawn, AllCommodify[14]);
			break;
		default:
			return;
		}
	}
}



void GameFrame::PrintInfoAndCount(Pawn* _pawn, Commodify* _commodify)
{
	_commodify->printSelfInfo();
	while (true)
	{
		print("��������������0Ϊ���أ���");
		_GETCHOOSE;//��������0�Ҹ�����Ǯ
		if (choose > 0) {
			if (choose <= _commodify->c_stock) {//���жϿ��
				if (_pawn->balance >= choose * _commodify->c_price) {//�ж����

					_commodify->purchase(_pawn,choose);
					_pawn->balance -= choose * _commodify->c_price;//��Ǯ
					_commodify->c_stock -= choose;//�ۿ��
					print("����ɹ�����ǰ��������Ϣ�鿴��");
					system("pause");
					return;

				}
				else { print("���㣡"); system("pause"); return; }
			}
			else { print("��治�㣡"); system("pause"); return; }
		}
		else return;
	}
}



void GameFrame::Attack(Pawn* _pawn)
{
	AI* EnemyAI = this->CreatAI();
	short EnemyMaxHP = EnemyAI->m_HP;
	AttackCycleAmount = 1;
	//ѭ����һ��Ѫ��<=0
	while (true)

	{
		cout << "==============��" << AttackCycleAmount+1 << "�غϿ�ʼ��==============" << endl;
		cout << "���Ѫ����" << _pawn->p_HP << endl;
		cout << "�з�Ѫ����" << EnemyAI->m_HP << endl;
		//�ҷ��غ�
		print("----------------------------------");
		print("�ֵ���Ļغϣ�");
		_pawn->initialize(); //ǰ��ʼ��
		this->PawnRound(_pawn, EnemyAI);

		//�ҷ��غϽ��� �ж�Ѫ�� �˴�������չ�����ж�
		_JUDGESTATE

		//�з��غ�
		print("----------------------------------");
		print("�ֵ��з��غϣ�");
		Sleep(_RAND * 1000);
		EnemyAI->initialize(_pawn->weapon_ptr); //��ʼ��
		this->MonsterRound(_pawn,EnemyAI);
		print("==============���غϽ�����==============");


		//�з��غϽ��� �ж�Ѫ��
		_JUDGESTATE
		AttackCycleAmount++;
		
	}
	cout << endl;
	print("**************�غϽ���***************");
	cout << endl;

	if (EnemyAI->m_HP <= 0) {//ʤ��֮�����ӳɹ����Լ��Ӷḡ���ж�
		this->AttackSuccesAmout++; 

		if (_pawn->prop_ptr) {//�жϻ���
			if (_pawn->prop_ptr->commodify_index == 15) {
				_pawn->p_HP += EnemyMaxHP * 0.2;
				cout << "(�Ӷḡ����Ч���ָ�" << EnemyMaxHP * 0.2 << "��Ѫ��)" << endl;
			}
		}
	}

	_pawn->balance += AttackSuccesAmout * 20;
	cout << "<ս��ʤ�����������" << AttackSuccesAmout * 20<<">" << endl;
	if (_pawn->p_HP > _pawn->Max_HP) _pawn->p_HP = _pawn->Max_HP;
	system("pause");

}


AI* GameFrame::CreatAI()
{
	float damage;
	float hp;

	damage = this->AttackSuccesAmout * 5 + 10; //10��100�ǻ����˺���Ѫ��
	hp = this->AttackSuccesAmout * 15 + 100;
	AI* ReturnValue = new AI(hp, damage);
	return ReturnValue;
}



//�˴�����չ��һغϵ���Ϊ
void GameFrame::PawnRound(Pawn* _pawn, AI* _ai) {
	while (true)
	{
		print("ս������������1�����߲���������2��");
		_GETCHOOSE;
		switch (choose)
		{
		case 1:
			_pawn->weapon_ptr->PawnRound(_pawn, _ai);
			return;
		case 2:
			_pawn->UseProp(_ai);
		default:
			break;
		}
		
	}
	
}

void GameFrame::MonsterRound(Pawn* _pawn,AI* _ai)
{
	_ai->BehaviorLogic(_pawn);//AI��Ϊ��
	//�˴������ӻغϵ��е�Ԫ��
	
}










