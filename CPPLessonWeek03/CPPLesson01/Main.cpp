#include <iostream>

// ��������(�����Ͷ��嶼Ҫ��inline�ؼ���)��
//	1. �ڱ���ʱ�Ὣ�������ڵ��߼����Ƶ��������������õĵط�
//	2. ������������ٺ�������ʱ��������ģ�ͬʱҲ�����Ӻ����屻��θ��Ƶ��ڴ�ռ��

inline void InlineFunc()
{
	using namespace std;
	cout << "I am inline func." << endl;
}

// �꣺
//	1. ��ߴ���εĸ���
//	2. �ڱ���ʱ�ڣ��Ὣ�귭��ɴ���ν��б���

#define _COUT cout <<

void MacroFunc()
{
	using namespace std;
	_COUT "I am a MacroFunc" << endl;
}

#undef _COUT // ж�غ֮꣬��Ĵ���Ͳ���ʹ��_COUT

// �������ĺ꣺
//	1. ��Ĳ�����������ʵ�����ݣ�ʵ����Ҳ�ǽ�����Ƭ�δ������ڲ�
#define _MULTI(a, b) a * b
//	2. �����������ȼ������⣬����������������
#define _MAX(a, b) (((a) > (b)) ? (a) : (b))

void MarcoFuncWithArgs()
{
	using namespace std;

	// �˴������Ľ���൱�ڣ���������
	// cout << 10 + 10 * 10 << endl;
	cout << _MULTI(10 + 10, 10) << endl;

	cout << _MAX(10 + 10, 10) << endl;
}

// �������ͱ���
//	1. typedef ԭ���� ����

void Alias()
{
	using namespace std;
	struct User { string name; int age; int sex; };
	// �����������ͱ���
	typedef int _INT;
	_INT a = 0;

	// �ṹ�����
	typedef User _USER;
	_USER user = { "amao", 25, 1 };

	// ����ָ�����
	typedef void(*_FUNCPTR)(void);
	_FUNCPTR alias_ptr = Alias;
}

// ����
// 1. �����ֳ�Ϊ�����ı�����ʹ�ñ�ָ�뷽��
void QuoteArgs(int &quote)
{
	quote = 2022;
}

void Quote()
{
	using namespace std;
	int i = 123;
	QuoteArgs(i);
	int& ii = i; // ���õ���Ϊ�����ͱ�����Ϊһ��
	cout << ii << endl;

	string str = "1000";
	const string& iii = str;
	const string* iptr = &iii;

	str = "2000"; // ��str��ֵ��Ȼ����Ӱ�쳣�� iii ��ֵ��������
	//iii = "3000"; �����Ը�������ֵ

	cout << str << endl;
	cout << iii << endl;
	cout << "sizeof(&iii)" << sizeof(iii) << endl;
	cout << "sizeof(*iii)" << sizeof(iptr) << endl;

	//int iiii = 1000;
	//const int& iiiii = 1000;
	//int arrays[iiiii]; //�������ò�����Ϊ��������ʱ�ĳ��Ȳ���

	//const int iiii = 1000;
	//const int* iiiii = &iiii;
	//*iiiii = 1001; // ʹ��ָ��Ҳ�����޸ĳ���

	// ��ֵ���ã��������ö��������ֵ
	//int&& i = 123;
	//i = 456;// ��ֵ������Ȼ���Ը�ֵ��ֻ�����������ö����������ֵ
}

// �����ռ�
namespace abc
{
	using namespace std;
	string name = "";
	void NamespaceFunc()
	{
		cout << "I am a NamespaceFunc." << endl;
	}
}

//�����
#include <ctime>
void GetRandomValue()
{
	using namespace std;
	srand((unsigned int)time(NULL));//����������ӣ�time(NULL)���ص�ǰϵͳ����
	int rand1 = rand();
	int rand2 = rand();
	cout << rand1 << endl;
	cout << rand2 << endl;
}

int main()
{
	void(*InlinefuncPtr)(void) = InlineFunc;
	(*InlinefuncPtr)();
	MacroFunc();
	MarcoFuncWithArgs();
	Quote();
	using namespace abc;
	NamespaceFunc();
	
	//����� ��Ϊtime(NULL)����ϵͳ����������������Ӵ���ʲ���
	GetRandomValue();
	GetRandomValue();
	GetRandomValue();

	system("pause");
}