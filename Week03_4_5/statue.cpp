#include "statue.h"
#include"AllMacro.h"
#include"Pawn.h"

void statue::Use(Pawn* _pawn)
{
	statue* temp = new statue;
	_pawn->SetProps(temp);
}

void statue::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(statue)
}

statue::statue()
{
	commodify_index = 15;
	c_stock = 1;
	c_price = 70;
	strcpy_s(c_name, "�Ӷḡ��");
	strcpy_s(depict, "<����>���ܵ���ʱ���ָ�����Ѫ����20%��");
}
