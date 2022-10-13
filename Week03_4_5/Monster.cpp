#include "Monster.h"
#include <iostream>
#include"Weapon.h"

#include "AllMacro.h"

using namespace std;
Monster::Monster()
{
    
	name = "С��";
	m_HP = 100.f;
	BaseDamage = 10.f;
	//debuff = DEBUFF::Ehealth;
	
}

Monster::Monster(float hp, float damage):m_HP(hp), BaseDamage(damage)
{
	name = "С��";
	debuff = nullptr;
	
}

//�����˺������� & �������˺��ı�
void Monster::GetHurt(float damage)
{
	float DefenseFluctuate = _RANDFORRANGE(30, 50);
	DefenseFluctuate /= 100;
	if (SearchBUFF(DEBUFFKind::Edefense)) damage *= DefenseFluctuate;

	m_HP -= damage;
	cout << "<�з��ܵ���" << damage << "���˺���>"<<  endl;

}



//��ʼ�������ܹ����󣬿�ʼ�ж�ǰ 
//debuff����
void Monster::initialize(Weapon* _weapon)

{
	//�пշ���
	if (!debuff) return;

	//�ǿմ���
	short size = _GETSIZE(debuff);
	_TRAVEL if (debuff[i].surplus == 0) RemoveBuff(i);//�Ƴ�ʣ��ʱ����0��BUFF
	
	if (SearchBUFF(DEBUFFKind::Efiring))this->Firing(_weapon);

	




	_TRAVEL debuff[i].surplus--;

	
}

void Monster::AddBuff(DEBUFFKind _debuff)
{
	//��ָ������
	if (!debuff) { debuff = new DEBUFF(_debuff); return; }
	

	//�ǿ�ָ�����
	int size = _GETSIZE(debuff);
	int newSize = size + 1;
	DEBUFF* temp = new DEBUFF[newSize];


	//��������
	for (int i = 0; i < size; i++) {
		temp[i] = debuff[i];
	}


	//�������
	DEBUFF AddTemp(_debuff);
	temp[size] = AddTemp;
	_SWEEPPTR(debuff);


	//������������ֵ����ȥ
	debuff = new DEBUFF[newSize];

	for (int i = 0; i < newSize; i++) {
		debuff[i] = temp[i];
	}
	_SWEEPPTR(temp);

}

void Monster::AddBuff(DEBUFF* _debuff)
{
	if (!debuff) { debuff = _debuff; return; }

	//�ǿ�ָ�����
	int size = _GETSIZE(debuff);
	int newSize = size + 1;
	DEBUFF* temp = new DEBUFF[newSize];
	//��������
	for (int i = 0; i < size; i++) {
		temp[i] = debuff[i];
	}
	//�������
	temp[size] = *_debuff;
	_SWEEPPTR(debuff);
	//������������ֵ����ȥ
	debuff = new DEBUFF[newSize];

	for (int i = 0; i < newSize; i++) {
		debuff[i] = temp[i];
	}
	_SWEEPPTR(temp);

}

bool Monster::SearchBUFF(DEBUFFKind _debuff)
{
	//�пշ���
	if (!debuff) return false;
	//�ǿղ�ѯ
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
	//��ֵ����ʱ����
	DEBUFF* temp = new DEBUFF[newSize];
	short j = 0;
	_TRAVEL{
		if (i != index) {

			temp[j] = debuff[i];
			j++;
		}
	}
	_SWEEPPTR(debuff);

	//��ֵ��ȥ
	size--;
	debuff = new DEBUFF[size];
	_TRAVEL{
		debuff[i] = temp[i];
	}
	_SWEEPPTR(temp);

}




//buff��Ч�ʹ�ӡ�ı�
void Monster::Firing(Weapon* _weapon)
{


	print("[������Ч�ˣ�]");
	if (!_BETWEEN(_weapon->FiringDamage, 0, 100)) { this->GetHurt(5); return; }
	this->GetHurt(_weapon->FiringDamage);
	

}

	

