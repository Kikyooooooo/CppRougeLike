#include<iostream>
#include<string>
#include<ctime>
#include "Weapon.h"
#include "Monster.h"
#include "GameFrame.h"
#include "Pawn.h"
#include "Sword.h"
#include "Wand.h" 
#include "AI.h"
#include "Commodify.h"

#include "AllMacro.h"

using namespace std;

int main() {

	srand((unsigned)time(NULL));
	
	Pawn* newPawn = new Pawn;
	GameFrame* newGame = new GameFrame;
	newGame->MainMenu(newPawn);

	system("pause");

}