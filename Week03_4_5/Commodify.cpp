#include "Commodify.h"
#include "AllMacro.h"
#include "Pawn.h"

void Commodify::purchase(Pawn* _pawn, int amount)
{
}

void Commodify::Use(Pawn* _pawn)
{
}

void Commodify::Use(Monster* _monster)
{
}


void Commodify::printSelfInfo()
{
	cout << "-----------------------------" << endl;
	cout << "���ƣ�" << this->c_name<<endl;
	cout << "��棺" << this->c_stock << endl;
	cout << "�۸�" << this->c_price << endl;
	cout << "��Ʒ������" << this->depict << endl;
	cout << "-----------------------------" << endl;
}


