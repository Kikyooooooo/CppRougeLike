#pragma once
#include<iostream>


struct Postprocessor//后处理
{
	float CauseDamage = 0.0f;
	float Suckblood = 0.0f;
	bool IsDizzy = false;
	bool IsCrit = false;
	bool IsFiring = false;

};

typedef Postprocessor post;
class Pawn;
class AI;

class Weapon
{

protected:
	float base_damage;
	
	virtual bool GetBoolForRate(int rate) final;
public:
	float FiringDamage;
	float base_defense = 0.5;
	std::string w_name;
	//行为
	Weapon();
	virtual void PawnRound(Pawn* _pawn,AI* _ai) = 0;
	virtual post CauseDamage();


};

