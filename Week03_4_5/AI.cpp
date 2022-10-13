#include "AI.h"
#include "Pawn.h"
#include "Monster.h"
#include"AI.h"

#include "AllMacro.h"

using namespace std;

void AI::BehaviorLogic(Pawn* _pawn)//行为树
{
	const float damage = _RANDFORRANGE(-4,5) +  this->BaseDamage;
	
	if (SearchBUFF(DEBUFFKind::Edizzy)) _NOTHING
	if(SearchBUFF(DEBUFFKind::Efrost)) _NOTHING

	if (damage > _pawn->p_HP) {
		this->attack(_pawn, damage);//攻击行为
	}
	else if (this->m_HP < 50 && _RAND>50) {
		//这里写防御 暂时偷懒不写函数了 但buff复杂的情况下要写函数
		AddBuff(DEBUFFKind::Edefense);
		print(this->name + "进入防御状态");
	}
	else {
		//暂时写攻击
		this->attack(_pawn, damage);
	}


}


//AI的伤害后处理+状态传递+伤害传递
void AI::attack(Pawn* _pawn, float damage,EPlayerState newbuff)
{
	float causedamage = damage;

	_pawn->GetHurt(damage);

}



AI::AI() : Monster()
{
}

AI::AI(float hp, float damage) : Monster(hp,damage)
{
}

//获得debuff，buff叠加时需要在这写判断





