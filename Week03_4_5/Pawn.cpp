#include "Pawn.h"
#include "AI.h"
#include "Monster.h"
#include "Weapon.h"
#include <string>
#include <windows.h>
#include "Commodify.h"

#include "AllMacro.h"

using namespace std;


//���캯��
Pawn::Pawn()
{
	State = nullptr;
	name = "����֮��";
	p_HP = 100.f;
	Max_HP = 100.f;
	weapon_ptr = nullptr;
	warehouse = nullptr;
	balance = 1000;
}


//�����˺�&����&�ı�������ı�������ڿ��Ը����ȥ
void Pawn::Attack(class AI* _ai)
{
	//�����˺�&�ı�
	
	post i = weapon_ptr->CauseDamage();
	if (SearchBUFF(EPlayerState::EPower)) i.CauseDamage *= 1.5;//����ҩ��
	
	if (this->prop_ptr) {//�����ж�
		if (this->prop_ptr->commodify_index == 13) i.CauseDamage *= 1.7;//��ӡ
		if (this->prop_ptr->commodify_index == 14 && this->p_HP <= this->Max_HP / 2)i.CauseDamage *= 1.5;//���н�
	}
	
	cout << "���ι���" << (i.IsCrit ? "�����˱����������" : "�����") << i.CauseDamage << "���˺�" << endl;
	
	if (i.IsDizzy)print("ѣ��Ч����Ч�������»غ��޷��ж�");
	if (i.Suckblood > 0)print("[���������Ѫ" + to_string(i.Suckblood) + "��]");
	if (i.IsFiring)print("[���ι���������գ�]");

	//����
	this->p_HP += i.Suckblood;


	//�˺�&״̬����
	//״̬�����߼�д����
	_ai->GetHurt(i.CauseDamage);
	if (i.IsDizzy) _ai->AddBuff(DEBUFFKind::Edefense);//ѣ��
	if (i.IsFiring)  _ai->AddBuff(DEBUFFKind::Efiring);//����
	
}

//����weponָ��
void Pawn::SetWeapon(Weapon* weapon)
{
	this->weapon_ptr = weapon;
	Sleep(500);
	print("װ����ɣ�");
}

void Pawn::SetProps(Commodify* _prop)
{
	this->prop_ptr = _prop;
	Sleep(500);
	print("װ����ɣ�");
}


void Pawn::AddProp(Commodify** _newProp)
{
	//��ָ������(�ձ�������)
	if (!warehouse){ warehouse = _newProp; return; }
	//�����ظ�����(�ѵ�)
	short size = _GETSIZE(warehouse);
	//�ж��Ƿ��ظ�
	if (SearchProp((*_newProp)->commodify_index)) {
		//�����ҵ��ظ�����++
		_TRAVEL if (warehouse[i]->commodify_index == (*_newProp)->commodify_index) {
			warehouse[i]->c_stock++;
			return;
		}
	
	}

	//����µ�������
	short newSize = size + 1;
	Commodify** temp = new Commodify * [newSize];

	//��ֵ��temp
	_TRAVEL temp[i] = warehouse[i];
	temp[size] = *_newProp;
	_SWEEPPTR(warehouse)

	//��ֵ����
	size++;//��һ������Ϊ����ʹ�ú꣬��������дforѭ��
	warehouse = new Commodify * [newSize];
	_TRAVEL warehouse[i] = temp[i];
	_SWEEPPTR(temp);
}

void Pawn::AddProp(short index)
{
	int size = _GETSIZE(warehouse);
	_TRAVEL if (warehouse[i]->commodify_index == index) {
		warehouse[i]->c_stock++;
	}

}

bool Pawn::SearchProp(int index)
{
	if (!warehouse) return false;
	short size = _GETSIZE(warehouse);
	_TRAVEL if (warehouse[i]->commodify_index == index) return true;
	return false;
}

void Pawn::RemoveProps(int index)
{
	if (!SearchProp(index)) return;
	
	short size = _GETSIZE(warehouse);
	short eliminate_index;//������Ϊ0����ô�ӱ��������Ƴ�
	_TRAVEL if (warehouse[i]->commodify_index == index)
	{
		warehouse[i]->c_stock--;
		if (warehouse[i]->c_stock <= 0)  eliminate_index = i; 
		else return;//���<=0����������Ƴ�����
	}

	//�Ƴ�����
	short newSize = size - 1;
	short j = 0;
	Commodify** temp = new Commodify * [newSize];
	_TRAVEL if (i != eliminate_index)
	{
		temp[j] = warehouse[i];
		j++;
	}
	_SWEEPPTR(warehouse)

	//��ֵ��ȥ
	warehouse = new Commodify * [newSize];
	size--;
	_TRAVEL warehouse[i] = temp[i];




}

void Pawn::CheckPersonInfo()
{
	while (true) {
	
		system("cls");
	cout << "���֣�" << this->name << endl;
	cout << "Ѫ����" << this->p_HP << endl;
	cout << "��ң�" << this->balance << endl;
	cout << "������" << (this->weapon_ptr ? this->weapon_ptr->w_name: "δװ��" )<< endl;
	cout << "������" << (this->prop_ptr ? this->prop_ptr->c_name : "δװ��" )<< endl;

	cout << "---------����---------" << endl;
	if (!warehouse) { print("����Ϊ��!"); system("pause"); return; }
	int size = _GETSIZE(warehouse);
	if (size == 0) { print("����Ϊ��!"); system("pause"); return; }

	print(size);
	_TRAVEL
		cout << i + 1 << ".  " << warehouse[i]->c_name << "  ������" << warehouse[i]->c_stock << endl;
	cout << "----------------------" << endl;
		print("���������Ӧ��Ų鿴��ϸ��Ϣ��ʹ��,����0����:");
		_GETCHOOSE;
		if (choose == 0) return;
		int index = choose - 1;
		if (!warehouse[index]) { print("��������"); system("pause"); continue; }
		//��ӡ���ݺͲ���
		warehouse[index]->printSelfInfo();
		
		print("����1ʹ�ã�����2����������0���أ�");
		print("��ѡ��");
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (_BETWEEN(warehouse[index]->commodify_index, 6, 8) || _BETWEEN(warehouse[index]->commodify_index, 11, 12)) { print("��ս����ʹ�ã�"); system("pause"); return; }
			warehouse[index]->Use(this);
			this->RemoveProps(warehouse[index]->commodify_index);
			system("pause");
			break;
		case 2:
			this->RemoveProps(warehouse[index]->commodify_index);
			print("�����ɹ���");
			system("pause");
			break;
		case 0:
			return;
		default:
			print("��������");
			system("pause");
			break;
		}
		

	}

	
}



//�˴�����д�µĸ���ҵ�buff���Լ�buff���ӵ��߼��ж�


//�����˺������� & �������˺��ı�
void Pawn::GetHurt(int damage)
{
	int _damage = damage;

	if (this->prop_ptr) {
		if (this->prop_ptr->commodify_index == 13) _damage *= 1.3;
	}

	//�˴�����д���״̬��,�յ��˺������ӻ����
	if (SearchBUFF(state::Edefense))_damage *= weapon_ptr->base_defense;

	p_HP -= _damage;
	print("****���˶��������" + to_string(_damage) + "���˺�****");

	

}

//ս������ʹ�õ���
void Pawn::UseProp(AI* _monster)
{
	//��ӡ����
	while (true)
	{
	    int size = _GETSIZE(warehouse);
		if (!warehouse || size == 0) { print("����Ϊ�գ�"); return; }
	    print(size);
	    _TRAVEL
		    cout << i + 1 << ".  " << warehouse[i]->c_name << "  ������" << warehouse[i]->c_stock << endl;
	    _GETCHOOSE;
		choose--;
		//�жϵ����ܲ�����
		if (_BETWEEN(warehouse[choose]->commodify_index, 1, 5)) { print("����ֻ����ս�������󻻣�"); return; }
	    if (_BETWEEN(warehouse[choose]->commodify_index, 13, 15)) { print("װ��ֻ����ս�������󻻣�"); return; }
		//�ж����ø��Լ����ǵ���
		if (_BETWEEN(warehouse[choose]->commodify_index, 8, 12)) warehouse[choose]->Use(this);
		    else warehouse[choose]->Use(_monster);


		cout << "ʹ��" << warehouse[choose]->c_name << "�ɹ���" << endl;
		this->RemoveProps(warehouse[choose]->commodify_index);
		return;
	}
}


//��ʼ�����������/���� �ܵ�����֮�󣬿�ʼ�ж�֮ǰ
//���Dizzy״̬Ҫ������Defense״̬Ҫ����
void Pawn::initialize() {
	if (!State) return;

	//�ǿմ���
	short size = _GETSIZE(State);
	_TRAVEL if (State[i].surplus == 0) RemoveBuff(i);//�Ƴ�ʣ��ʱ����0��BUFF






	_TRAVEL State[i].surplus--;//ʣ��ʱ��-1

}

void Pawn::AddBuff(state _newbuff)
{
	//��ָ������
	if (!State) { State = new playerState(_newbuff); return; }


	//�ǿ�ָ�����
	int size = _GETSIZE(State);
	int newSize = size + 1;
	playerState* temp = new playerState[newSize];


	//��������
	for (int i = 0; i < size; i++) {
		temp[i] = State[i];
	}


	//�������
	playerState AddTemp(_newbuff);
	temp[size] = AddTemp;
	_SWEEPPTR(State);


	//������������ֵ����ȥ
	State = new playerState[newSize];

	for (int i = 0; i < newSize; i++) {
		State[i] = temp[i];
	}
	_SWEEPPTR(temp);
}

void Pawn::AddBuff(playerState* _newbuff)
{
	//��ָ������
	if (!State) { State = _newbuff; return; }


	//�ǿ�ָ�����
	int size = _GETSIZE(State);
	int newSize = size + 1;
	playerState* temp = new playerState[newSize];


	//��������
	for (int i = 0; i < size; i++) {
		temp[i] = State[i];
	}


	//�������
	temp[size] = *_newbuff;
	_SWEEPPTR(State);


	//������������ֵ����ȥ
	State = new playerState[newSize];

	for (int i = 0; i < newSize; i++) {
		State[i] = temp[i];
	}
	_SWEEPPTR(temp);
}

void Pawn::RemoveBuff(int index)
{
	short size = _GETSIZE(State);
	if (index >= size)return;
	short newSize = size - 1;
	//��ֵ����ʱ����
	playerState* temp = new playerState[newSize];
	short j = 0;
	_TRAVEL{
		if (i != index) {

			temp[j] = State[i];
			j++;
		}
	}
	_SWEEPPTR(State);

	//��ֵ��ȥ
	size--;
	State = new playerState[size];
	_TRAVEL{
		State[i] = temp[i];
	}
	_SWEEPPTR(temp);


}

bool Pawn::SearchBUFF(state _buff)
{
	//�пշ���
	if (!State) return false;
	//�ǿղ�ѯ
	int size = _GETSIZE(State);
	_TRAVEL{
		if (State[i]._state == _buff) return true;
	}
	return false;
}