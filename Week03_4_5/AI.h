#pragma once
#include <iostream>
#include"Monster.h"
#include"Pawn.h"



class Pawn;

class AI : public Monster //�����Ĺ�����ai+monster
{
	

public:
	void BehaviorLogic(Pawn* _pawn);
	void attack(Pawn* _pawn, float damage,EPlayerState newbuff = state::ENULL);
	

	AI();
	AI(float hp, float damage);
};

