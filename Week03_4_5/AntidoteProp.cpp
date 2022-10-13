#include "AntidoteProp.h"
#include "Monster.h"
#include "AllMacro.h"
#include "Pawn.h"

void AntidoteProp::Use(Pawn* _pawn)
{
	int size = _GETSIZE(_pawn->State);//
	_TRAVEL if (_pawn->State[i]._state != state::Edefense && _pawn->State[i]._state != state::EPower) _pawn->RemoveBuff(i);

}

void AntidoteProp::purchase(Pawn* _pawn, int amount)
{
	_PURCHASE(AntidoteProp)
}

AntidoteProp::AntidoteProp()
{
	strcpy_s(c_name, "解药");
	commodify_index = 12;
	c_stock = 1;
	c_price = 25;
	strcpy_s(depict, "<道具>移除一切负面状态。");
}
