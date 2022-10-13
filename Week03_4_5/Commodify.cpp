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
	cout << "名称：" << this->c_name<<endl;
	cout << "库存：" << this->c_stock << endl;
	cout << "价格：" << this->c_price << endl;
	cout << "物品描述：" << this->depict << endl;
	cout << "-----------------------------" << endl;
}


