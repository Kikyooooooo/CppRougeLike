#include "Weapon.h"

#include "AllMacro.h"
Weapon::Weapon()
{
}


bool Weapon::GetBoolForRate(int rate)
{
    if (rate <= 0)return false;//�пշ���
    if (_RAND < rate) return true;
    return false;
}

post Weapon::CauseDamage()
{
    post ReturnValue;
    return ReturnValue;
}
