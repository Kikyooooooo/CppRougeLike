#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Pawn;
class Weapon;
class Monster;
class Commodify
{
public:
	char c_name[40];
	short commodify_index;
	short c_stock;
	short c_price;
	char depict[100];

	virtual void purchase(Pawn* _pawn, int amount);
	virtual void Use(Pawn* _pawn);
	virtual void Use(Monster* _monster);
	virtual void printSelfInfo();
};

