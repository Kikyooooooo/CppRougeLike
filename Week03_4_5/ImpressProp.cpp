#include "ImpressProp.h"
#include"AllMacro.h"
#include"Pawn.h"

void ImpressProp::Use(Pawn* _pawn)
{
	ImpressProp* temp = new ImpressProp;
	_pawn->SetProps(temp);
}

void ImpressProp::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(ImpressProp)
}

ImpressProp::ImpressProp()
{
	commodify_index = 3;
	c_stock = 1;
	c_price = 80;
	strcpy_s(c_name, "��ӡ");
	strcpy_s(depict, "<����>�����յ����˺���������������");

}
