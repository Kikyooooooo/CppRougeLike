#pragma once
#include<iostream>


enum class DEBUFFKind
{
	ENULL,
	Edizzy,
	Edefense,
	Efrost,
	Efiring
};



struct DEBUFF
{
	DEBUFFKind _debuff;
	short surplus;
	//Ĭ�Ϲ��죬�����ڴ�������
	DEBUFF() {
	
		_debuff = DEBUFFKind::ENULL;
		surplus = -1;
	}
	//����Ӧ���죬ֻ�ø�debuff����
	DEBUFF(DEBUFFKind construct_debuff) {
		_debuff = construct_debuff;
		surplus = -1;
		//����debuff�����Զ�ƥ��
		switch (construct_debuff)
		{
		case DEBUFFKind::Edizzy:
			surplus = 1;
			break;
		case DEBUFFKind::Edefense:
			surplus = 0;
			break;
		case DEBUFFKind::Efrost:
			surplus = 2;
			break;
		case DEBUFFKind::Efiring:
			surplus = 3;
			break;
		default:
			break;
		}

	}
	DEBUFF(DEBUFFKind construct_debuff, short _surplus):_debuff(construct_debuff),surplus(_surplus){}
};


class Weapon;

class Monster
{
protected:

	float BaseDamage;
	DEBUFF* debuff; //��̬����
public:
	const float defaultDamage = 10; //�������������ñ�����
	const float defaultHP = 100;
//	DEBUFF debuff;
	float m_HP;
	std::string name;
	Monster();
	Monster(float hp, float damage);
	void GetHurt(float damage);
	void initialize(Weapon* _weapon);
	void AddBuff(DEBUFFKind _debuff);
	void AddBuff(DEBUFF* _debuff);
	bool SearchBUFF(DEBUFFKind _debuff);
	void RemoveBuff(int index);

	//buff��Ч�ʹ�ӡ�ı�
	void Firing(Weapon* _weapon);
};

