#pragma once
#define print(a) cout<<a<<endl
#define _RAND rand() % 100 + 1
#define _NOTHING {print(this->name + "ʲôҲû����");return;}

#define _GETSIZE(a) _msize(a) / sizeof(*a)
#define _SWEEPPTR(a) delete[]a;a = nullptr; 
#define _TRAVEL for (int i = 0; i < size; i++)

#define _GETCHOOSE short choose = -1; print("��ѡ��:");cin >> choose;

#define _RANDFORRANGE(a,b) rand()%(b - a + 1) + a

#define _JUDGESTATE if (_pawn->p_HP <= 0) {\
print("���Ѫ��Ϊ0����Ϸ������");break;}\
else if (EnemyAI->m_HP <= 0) {\
print("�з�Ѫ��Ϊ0����Ϸ������");break;}

#define _LOADCOMMODIFY(a,b,c) AllCommodify[a] = new b;AllCommodify[a]->c_stock = c
#define _MODIFYUSEFORWEAPON(a) a* _a = new a;_pawn->SetWeapon(_a);





#define _PURCHASE(a) int size;\
if (_pawn->SearchProp(this->commodify_index)) {\
	size = amount;\
	_TRAVEL _pawn->AddProp(this->commodify_index);\
	return;\
}\
Commodify** temp = new Commodify*;\
*temp = new a;\
_pawn->AddProp(temp);\
size = amount - 1;\
_TRAVEL _pawn->AddProp(this->commodify_index);\


#define _BETWEEN(a,b,c) a>=b && a<=c