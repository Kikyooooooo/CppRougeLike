#include "Pawn.h"
#include "AI.h"
#include "Monster.h"
#include "Weapon.h"
#include <string>
#include <windows.h>
#include "Commodify.h"

#include "AllMacro.h"

using namespace std;


//构造函数
Pawn::Pawn()
{
	State = nullptr;
	name = "无名之辈";
	p_HP = 100.f;
	Max_HP = 100.f;
	weapon_ptr = nullptr;
	warehouse = nullptr;
	balance = 1000;
}


//计算伤害&后处理&文本输出，文本输出后期可以隔离出去
void Pawn::Attack(class AI* _ai)
{
	//计算伤害&文本
	
	post i = weapon_ptr->CauseDamage();
	if (SearchBUFF(EPlayerState::EPower)) i.CauseDamage *= 1.5;//怪力药丸
	
	if (this->prop_ptr) {//护符判定
		if (this->prop_ptr->commodify_index == 13) i.CauseDamage *= 1.7;//烙印
		if (this->prop_ptr->commodify_index == 14 && this->p_HP <= this->Max_HP / 2)i.CauseDamage *= 1.5;//七刃剑
	}
	
	cout << "本次攻击" << (i.IsCrit ? "产生了暴击并造成了" : "造成了") << i.CauseDamage << "点伤害" << endl;
	
	if (i.IsDizzy)print("眩晕效果生效，敌人下回合无法行动");
	if (i.Suckblood > 0)print("[本次造成吸血" + to_string(i.Suckblood) + "点]");
	if (i.IsFiring)print("[本次攻击造成灼烧！]");

	//后处理
	this->p_HP += i.Suckblood;


	//伤害&状态传递
	//状态传递逻辑写在这
	_ai->GetHurt(i.CauseDamage);
	if (i.IsDizzy) _ai->AddBuff(DEBUFFKind::Edefense);//眩晕
	if (i.IsFiring)  _ai->AddBuff(DEBUFFKind::Efiring);//灼烧
	
}

//设置wepon指针
void Pawn::SetWeapon(Weapon* weapon)
{
	this->weapon_ptr = weapon;
	Sleep(500);
	print("装备完成！");
}

void Pawn::SetProps(Commodify* _prop)
{
	this->prop_ptr = _prop;
	Sleep(500);
	print("装备完成！");
}


void Pawn::AddProp(Commodify** _newProp)
{
	//空指针流程(空背包流程)
	if (!warehouse){ warehouse = _newProp; return; }
	//道具重复流程(堆叠)
	short size = _GETSIZE(warehouse);
	//判断是否重复
	if (SearchProp((*_newProp)->commodify_index)) {
		//遍历找到重复项，库存++
		_TRAVEL if (warehouse[i]->commodify_index == (*_newProp)->commodify_index) {
			warehouse[i]->c_stock++;
			return;
		}
	
	}

	//添加新道具流程
	short newSize = size + 1;
	Commodify** temp = new Commodify * [newSize];

	//传值给temp
	_TRAVEL temp[i] = warehouse[i];
	temp[size] = *_newProp;
	_SWEEPPTR(warehouse)

	//传值回来
	size++;//这一步这是为了能使用宏，不用再手写for循环
	warehouse = new Commodify * [newSize];
	_TRAVEL warehouse[i] = temp[i];
	_SWEEPPTR(temp);
}

void Pawn::AddProp(short index)
{
	int size = _GETSIZE(warehouse);
	_TRAVEL if (warehouse[i]->commodify_index == index) {
		warehouse[i]->c_stock++;
	}

}

bool Pawn::SearchProp(int index)
{
	if (!warehouse) return false;
	short size = _GETSIZE(warehouse);
	_TRAVEL if (warehouse[i]->commodify_index == index) return true;
	return false;
}

void Pawn::RemoveProps(int index)
{
	if (!SearchProp(index)) return;
	
	short size = _GETSIZE(warehouse);
	short eliminate_index;//如果库存为0，那么从背包当中移除
	_TRAVEL if (warehouse[i]->commodify_index == index)
	{
		warehouse[i]->c_stock--;
		if (warehouse[i]->c_stock <= 0)  eliminate_index = i; 
		else return;//库存<=0就走下面的移除流程
	}

	//移除流程
	short newSize = size - 1;
	short j = 0;
	Commodify** temp = new Commodify * [newSize];
	_TRAVEL if (i != eliminate_index)
	{
		temp[j] = warehouse[i];
		j++;
	}
	_SWEEPPTR(warehouse)

	//传值回去
	warehouse = new Commodify * [newSize];
	size--;
	_TRAVEL warehouse[i] = temp[i];




}

void Pawn::CheckPersonInfo()
{
	while (true) {
	
		system("cls");
	cout << "名字：" << this->name << endl;
	cout << "血量：" << this->p_HP << endl;
	cout << "金币：" << this->balance << endl;
	cout << "武器：" << (this->weapon_ptr ? this->weapon_ptr->w_name: "未装备" )<< endl;
	cout << "护符：" << (this->prop_ptr ? this->prop_ptr->c_name : "未装备" )<< endl;

	cout << "---------背包---------" << endl;
	if (!warehouse) { print("背包为空!"); system("pause"); return; }
	int size = _GETSIZE(warehouse);
	if (size == 0) { print("背包为空!"); system("pause"); return; }

	print(size);
	_TRAVEL
		cout << i + 1 << ".  " << warehouse[i]->c_name << "  数量：" << warehouse[i]->c_stock << endl;
	cout << "----------------------" << endl;
		print("输入对于相应序号查看详细信息或使用,输入0返回:");
		_GETCHOOSE;
		if (choose == 0) return;
		int index = choose - 1;
		if (!warehouse[index]) { print("输入有误！"); system("pause"); continue; }
		//打印数据和操作
		warehouse[index]->printSelfInfo();
		
		print("输入1使用，输入2丢弃，输入0返回：");
		print("请选择：");
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (_BETWEEN(warehouse[index]->commodify_index, 6, 8) || _BETWEEN(warehouse[index]->commodify_index, 11, 12)) { print("仅战斗中使用！"); system("pause"); return; }
			warehouse[index]->Use(this);
			this->RemoveProps(warehouse[index]->commodify_index);
			system("pause");
			break;
		case 2:
			this->RemoveProps(warehouse[index]->commodify_index);
			print("丢弃成功！");
			system("pause");
			break;
		case 0:
			return;
		default:
			print("输入有误！");
			system("pause");
			break;
		}
		

	}

	
}



//此处可以写新的给玩家的buff，以及buff叠加的逻辑判断


//接受伤害并后处理 & 输出造成伤害文本
void Pawn::GetHurt(int damage)
{
	int _damage = damage;

	if (this->prop_ptr) {
		if (this->prop_ptr->commodify_index == 13) _damage *= 1.3;
	}

	//此处可以写别的状态下,收到伤害的增加或减少
	if (SearchBUFF(state::Edefense))_damage *= weapon_ptr->base_defense;

	p_HP -= _damage;
	print("****敌人对你造成了" + to_string(_damage) + "点伤害****");

	

}

//战斗当中使用道具
void Pawn::UseProp(AI* _monster)
{
	//打印道具
	while (true)
	{
	    int size = _GETSIZE(warehouse);
		if (!warehouse || size == 0) { print("背包为空！"); return; }
	    print(size);
	    _TRAVEL
		    cout << i + 1 << ".  " << warehouse[i]->c_name << "  数量：" << warehouse[i]->c_stock << endl;
	    _GETCHOOSE;
		choose--;
		//判断道具能不能用
		if (_BETWEEN(warehouse[choose]->commodify_index, 1, 5)) { print("武器只能在战斗结束后换！"); return; }
	    if (_BETWEEN(warehouse[choose]->commodify_index, 13, 15)) { print("装备只能在战斗结束后换！"); return; }
		//判断是用给自己还是敌人
		if (_BETWEEN(warehouse[choose]->commodify_index, 8, 12)) warehouse[choose]->Use(this);
		    else warehouse[choose]->Use(_monster);


		cout << "使用" << warehouse[choose]->c_name << "成功！" << endl;
		this->RemoveProps(warehouse[choose]->commodify_index);
		return;
	}
}


//初始化发生在玩家/敌人 受到攻击之后，开始行动之前
//因此Dizzy状态要持续、Defense状态要重置
void Pawn::initialize() {
	if (!State) return;

	//非空处理
	short size = _GETSIZE(State);
	_TRAVEL if (State[i].surplus == 0) RemoveBuff(i);//移除剩余时间是0的BUFF






	_TRAVEL State[i].surplus--;//剩余时间-1

}

void Pawn::AddBuff(state _newbuff)
{
	//空指针流程
	if (!State) { State = new playerState(_newbuff); return; }


	//非空指针添加
	int size = _GETSIZE(State);
	int newSize = size + 1;
	playerState* temp = new playerState[newSize];


	//拷贝流程
	for (int i = 0; i < size; i++) {
		temp[i] = State[i];
	}


	//添加流程
	playerState AddTemp(_newbuff);
	temp[size] = AddTemp;
	_SWEEPPTR(State);


	//拷贝结束，把值给回去
	State = new playerState[newSize];

	for (int i = 0; i < newSize; i++) {
		State[i] = temp[i];
	}
	_SWEEPPTR(temp);
}

void Pawn::AddBuff(playerState* _newbuff)
{
	//空指针流程
	if (!State) { State = _newbuff; return; }


	//非空指针添加
	int size = _GETSIZE(State);
	int newSize = size + 1;
	playerState* temp = new playerState[newSize];


	//拷贝流程
	for (int i = 0; i < size; i++) {
		temp[i] = State[i];
	}


	//添加流程
	temp[size] = *_newbuff;
	_SWEEPPTR(State);


	//拷贝结束，把值给回去
	State = new playerState[newSize];

	for (int i = 0; i < newSize; i++) {
		State[i] = temp[i];
	}
	_SWEEPPTR(temp);
}

void Pawn::RemoveBuff(int index)
{
	short size = _GETSIZE(State);
	if (index >= size)return;
	short newSize = size - 1;
	//传值给临时变量
	playerState* temp = new playerState[newSize];
	short j = 0;
	_TRAVEL{
		if (i != index) {

			temp[j] = State[i];
			j++;
		}
	}
	_SWEEPPTR(State);

	//传值回去
	size--;
	State = new playerState[size];
	_TRAVEL{
		State[i] = temp[i];
	}
	_SWEEPPTR(temp);


}

bool Pawn::SearchBUFF(state _buff)
{
	//判空返回
	if (!State) return false;
	//非空查询
	int size = _GETSIZE(State);
	_TRAVEL{
		if (State[i]._state == _buff) return true;
	}
	return false;
}