#pragma once
#include<iostream>

enum class EPlayerState {

	ENULL,
	Edefense,
	Efiring,
	Efrost,
	EPower

};

typedef EPlayerState state;

struct playerState
{
	state _state;
	int surplus;

	playerState() { _state = state::ENULL; surplus = -1; }

	playerState(state construct_state) {
		_state = construct_state;
		surplus = -1;
		switch (construct_state)
		{
		case EPlayerState::ENULL:
			break;
		case EPlayerState::Edefense:
			surplus = 0;
			break;
		case EPlayerState::Efiring:
			surplus = 2;
			break;
		case EPlayerState::Efrost:
			surplus = 1;
			break;
		default:
			break;
		}
	}

	playerState(state construct_state, int continue_cycle):_state(construct_state),surplus(continue_cycle){}

};

enum EWeapon {

	EWand, ESword

};

class Pawn
{
public:
	//��Ա
	playerState* State; //��̬����
	std::string name;
	float p_HP;
	float Max_HP;
	int balance;
	class Weapon* weapon_ptr;
	class Commodify* prop_ptr;
	class Commodify** warehouse; //����
	//��Ϊ
	Pawn();
	//ս�����
	void Attack(class AI* _ai);
	void SetWeapon(Weapon* weapon);
	void SetProps(Commodify* _prop);
	void GetHurt(int damage);
	void UseProp(AI* _monster);
	//�������
	void AddProp(Commodify** _newProp);
	void AddProp(short index);
	bool SearchProp(int index);
	void RemoveProps(int index);
	void CheckPersonInfo();
	//BUFF���
	void initialize();
	void AddBuff(state _newbuff);
	void AddBuff(playerState* _newbuff);
	void RemoveBuff(int index);
	bool SearchBUFF(state _buff);
};

