#include "AI.h"
#include "Pawn.h"
#include "Monster.h"
#include"AI.h"

#include "AllMacro.h"

using namespace std;

void AI::BehaviorLogic(Pawn* _pawn)//��Ϊ��
{
	const float damage = _RANDFORRANGE(-4,5) +  this->BaseDamage;
	
	if (SearchBUFF(DEBUFFKind::Edizzy)) _NOTHING
	if(SearchBUFF(DEBUFFKind::Efrost)) _NOTHING

	if (damage > _pawn->p_HP) {
		this->attack(_pawn, damage);//������Ϊ
	}
	else if (this->m_HP < 50 && _RAND>50) {
		//����д���� ��ʱ͵����д������ ��buff���ӵ������Ҫд����
		AddBuff(DEBUFFKind::Edefense);
		print(this->name + "�������״̬");
	}
	else {
		//��ʱд����
		this->attack(_pawn, damage);
	}


}


//AI���˺�����+״̬����+�˺�����
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

//���debuff��buff����ʱ��Ҫ����д�ж�





