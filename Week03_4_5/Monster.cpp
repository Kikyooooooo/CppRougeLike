#include "Monster.h"
#include <iostream>
#include"Weapon.h"

#include "AllMacro.h"

using namespace std;
Monster::Monster()
{
    
	name = "小怪";
	m_HP = 100.f;
	BaseDamage = 10.f;
	//debuff = DEBUFF::Ehealth;
	
}

Monster::Monster(float hp, float damage):m_HP(hp), BaseDamage(damage)
{
	name = "小怪";
	debuff = nullptr;
	
}

//接受伤害并后处理 & 输出造成伤害文本
void Monster::GetHurt(float damage)
{
	float DefenseFluctuate = _RANDFORRANGE(30, 50);
	DefenseFluctuate /= 100;
	if (SearchBUFF(DEBUFFKind::Edefense)) damage *= DefenseFluctuate;

	m_HP -= damage;
	cout << "<敌方受到了" << damage << "点伤害！>"<<  endl;

}



//初始化放在受攻击后，开始行动前 
//debuff管理
void Monster::initialize(Weapon* _weapon)

{
	//判空返回
	if (!debuff) return;

	//非空处理
	short size = _GETSIZE(debuff);
	_TRAVEL if (debuff[i].surplus == 0) RemoveBuff(i);//移除剩余时间是0的BUFF
	
	if (SearchBUFF(DEBUFFKind::Efiring))this->Firing(_weapon);

	




	_TRAVEL debuff[i].surplus--;

	
}

void Monster::AddBuff(DEBUFFKind _debuff)
{
	//空指针流程
	if (!debuff) { debuff = new DEBUFF(_debuff); return; }
	

	//非空指针添加
	int size = _GETSIZE(debuff);
	int newSize = size + 1;
	DEBUFF* temp = new DEBUFF[newSize];


	//拷贝流程
	for (int i = 0; i < size; i++) {
		temp[i] = debuff[i];
	}


	//添加流程
	DEBUFF AddTemp(_debuff);
	temp[size] = AddTemp;
	_SWEEPPTR(debuff);


	//拷贝结束，把值给回去
	debuff = new DEBUFF[newSize];

	for (int i = 0; i < newSize; i++) {
		debuff[i] = temp[i];
	}
	_SWEEPPTR(temp);

}

void Monster::AddBuff(DEBUFF* _debuff)
{
	if (!debuff) { debuff = _debuff; return; }

	//非空指针添加
	int size = _GETSIZE(debuff);
	int newSize = size + 1;
	DEBUFF* temp = new DEBUFF[newSize];
	//拷贝流程
	for (int i = 0; i < size; i++) {
		temp[i] = debuff[i];
	}
	//添加流程
	temp[size] = *_debuff;
	_SWEEPPTR(debuff);
	//拷贝结束，把值给回去
	debuff = new DEBUFF[newSize];

	for (int i = 0; i < newSize; i++) {
		debuff[i] = temp[i];
	}
	_SWEEPPTR(temp);

}

bool Monster::SearchBUFF(DEBUFFKind _debuff)
{
	//判空返回
	if (!debuff) return false;
	//非空查询
	int size = _GETSIZE(debuff);
	_TRAVEL{
		if (debuff[i]._debuff == _debuff) return true;
	}
	return false;

}


void Monster::RemoveBuff(int index)
{
	short size = _GETSIZE(debuff);
	if (index >= size)return;
	short newSize = size - 1;
	//传值给临时变量
	DEBUFF* temp = new DEBUFF[newSize];
	short j = 0;
	_TRAVEL{
		if (i != index) {

			temp[j] = debuff[i];
			j++;
		}
	}
	_SWEEPPTR(debuff);

	//传值回去
	size--;
	debuff = new DEBUFF[size];
	_TRAVEL{
		debuff[i] = temp[i];
	}
	_SWEEPPTR(temp);

}




//buff生效和打印文本
void Monster::Firing(Weapon* _weapon)
{


	print("[火焰生效了！]");
	if (!_BETWEEN(_weapon->FiringDamage, 0, 100)) { this->GetHurt(5); return; }
	this->GetHurt(_weapon->FiringDamage);
	

}

	

