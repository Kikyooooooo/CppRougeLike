//导入character
#include "GameFrame.h"
#include "Pawn.h"
#include "Monster.h"
#include "AI.h"
//导入武器
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

//其他
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
	cout << "当前位于地下" << this->AttackSuccesAmout << "层"<<endl;
	print("1.开始战斗");
	print("2.武器商店");
	print("3.个人信息");
	_GETCHOOSE;
	switch (choose) {
	case 1:
		if (!_pawn->weapon_ptr) { print("你还没装备武器，无法战斗！"); system("pause"); break; }//判空
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

	//结束时自己调自己 保证不会脱离系统
	this->MainMenu(_pawn);
}

void GameFrame::ArmsStore(Pawn* _pawn)
{
	while (true)
	{
	system("cls");
	print("1.火把");
	print("2.长枪");
	print("3.太刀");
	print("4.轩辕剑");
	print("5.观星杖");
	print("6.催眠弹");
	print("7.爆破弹");
	print("8.怪力药丸");
	print("9.回复药(小)");
	print("10.回复药（大）");
	print("11.秘药");
	print("12.解药");
	print("13.烙印");
	print("14.七刃剑");
	print("15.掠夺浮雕");
	print("---------------------------");
	std::cout << "当前金币：" << _pawn->balance <<std::endl;
	print("(输入0返回)");
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
		print("购买数量（输入0为返回）：");
		_GETCHOOSE;//数量大于0且给得起钱
		if (choose > 0) {
			if (choose <= _commodify->c_stock) {//先判断库存
				if (_pawn->balance >= choose * _commodify->c_price) {//判断余额

					_commodify->purchase(_pawn,choose);
					_pawn->balance -= choose * _commodify->c_price;//扣钱
					_commodify->c_stock -= choose;//扣库存
					print("购买成功！请前往个人信息查看！");
					system("pause");
					return;

				}
				else { print("余额不足！"); system("pause"); return; }
			}
			else { print("库存不足！"); system("pause"); return; }
		}
		else return;
	}
}



void GameFrame::Attack(Pawn* _pawn)
{
	AI* EnemyAI = this->CreatAI();
	short EnemyMaxHP = EnemyAI->m_HP;
	AttackCycleAmount = 1;
	//循环到一方血量<=0
	while (true)

	{
		cout << "==============第" << AttackCycleAmount+1 << "回合开始！==============" << endl;
		cout << "你的血量：" << _pawn->p_HP << endl;
		cout << "敌方血量：" << EnemyAI->m_HP << endl;
		//我方回合
		print("----------------------------------");
		print("轮到你的回合：");
		_pawn->initialize(); //前初始化
		this->PawnRound(_pawn, EnemyAI);

		//我方回合结束 判断血量 此处可以拓展其他判断
		_JUDGESTATE

		//敌方回合
		print("----------------------------------");
		print("轮到敌方回合：");
		Sleep(_RAND * 1000);
		EnemyAI->initialize(_pawn->weapon_ptr); //初始化
		this->MonsterRound(_pawn,EnemyAI);
		print("==============本回合结束！==============");


		//敌方回合结束 判断血量
		_JUDGESTATE
		AttackCycleAmount++;
		
	}
	cout << endl;
	print("**************回合结束***************");
	cout << endl;

	if (EnemyAI->m_HP <= 0) {//胜利之后，增加成功数以及掠夺浮雕判定
		this->AttackSuccesAmout++; 

		if (_pawn->prop_ptr) {//判断护符
			if (_pawn->prop_ptr->commodify_index == 15) {
				_pawn->p_HP += EnemyMaxHP * 0.2;
				cout << "(掠夺浮雕生效，恢复" << EnemyMaxHP * 0.2 << "点血量)" << endl;
			}
		}
	}

	_pawn->balance += AttackSuccesAmout * 20;
	cout << "<战斗胜利！金币增加" << AttackSuccesAmout * 20<<">" << endl;
	if (_pawn->p_HP > _pawn->Max_HP) _pawn->p_HP = _pawn->Max_HP;
	system("pause");

}


AI* GameFrame::CreatAI()
{
	float damage;
	float hp;

	damage = this->AttackSuccesAmout * 5 + 10; //10和100是基础伤害和血量
	hp = this->AttackSuccesAmout * 15 + 100;
	AI* ReturnValue = new AI(hp, damage);
	return ReturnValue;
}



//此处可拓展玩家回合的行为
void GameFrame::PawnRound(Pawn* _pawn, AI* _ai) {
	while (true)
	{
		print("战斗操作请输入1，道具操作请输入2：");
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
	_ai->BehaviorLogic(_pawn);//AI行为树
	//此处可增加回合当中的元素
	
}










