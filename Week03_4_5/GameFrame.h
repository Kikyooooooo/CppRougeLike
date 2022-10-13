#pragma once
#include<iostream>

using namespace std;
class Pawn;
class AI;
class Monster;
enum class GameState {

	EMainMenu,
	EINAttack,

};
class Commodify;
class GameFrame
{
private:
	GameState now;
	int AttackCycleAmount;
	int AttackSuccesAmout;
	
	void PawnRound(Pawn* _pawn,AI* _ai);
	void MonsterRound(Pawn* _pawn,AI* _ai);
public:
	GameFrame();
	Commodify* AllCommodify[15];
	void MainMenu(Pawn* _pawn);
	void Attack(Pawn* _pawn);
	void ArmsStore(Pawn* _pawn);
	void PrintInfoAndCount(Pawn* _pawn,Commodify* _commodify);
	AI* CreatAI();


};

