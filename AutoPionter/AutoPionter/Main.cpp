#include <iostream>
#include "AutoPointer.h"
#include "ReferenceManager.h"

using namespace std;

class A
{
public:
	~A ()
	{
		cout << "Delete A" << endl;
	}

	void SayHello()
	{
		cout << "A say Hello!" << endl;
	}
};


template<typename T>
void TempFuncPtr(T* Outer, void (T::*FuncPtr)())
{
	(Outer->*FuncPtr)();
}

class B
{
public:
	A* pa;

	B()
	{
		pa = nullptr;
	}
	 
	~B()
	{
		if (pa) delete pa;
		cout << "Delete B" << endl;
	}
};

//�������ͱ����һ�����й��������͵Ŀռ�
template <typename T>
class Temp
{
public:

	T* pt;
	
	Temp() : pt(nullptr)
	{
	}

	~Temp()
	{
		cout << "Delete Temp" << endl;
		delete pt;
	}
};

void Func()
{
	/*A* pa = new A;
	B pb = B();
	pb.pa = pa;

	cout << "����ģ�������������Ŀռ�" << endl;

	A* pa1 = new A;
	Temp<A> tp;
	tp.pt = pa1;*/

	//A* pa = new A;
	//AutoPointer<A> ap(pa);

	AutoPointer<A> ap(new A);
	// ����ģ���Ա����ָ��
	TempFuncPtr(new A, &A::SayHello);

	// ͨ������ָ����������߼�
	ap->SayHello();
	(*ap).SayHello();
	if (ap)
	{
		cout << "Ap type is Bool" << endl;
	}
}

// ��̬��Ա���Ա��������ʼ��
ReferenceManager* ReferenceManager::_instance = nullptr;
void TestReferenceManger()
{
	int* ip = new int;

	ReferenceManager::GetInstance()->AddReferencePointer(ip);
	cout << "��ǰ���ü���: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;
	ReferenceManager::GetInstance()->AddReferencePointer(ip);
	ReferenceManager::GetInstance()->AddReferencePointer(ip);
	ReferenceManager::GetInstance()->AddReferencePointer(ip);
	cout << "��ǰ���ü���: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;
	cout << "=======================" << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip);
	cout << "��ǰ���ü���: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip);
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip);
	cout << "��ǰ���ü���: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip);
	cout << "=======================" << endl;
	//cout << "��ǰ���ü���: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;

	int* ip2 = new int;
	ReferenceManager::GetInstance()->AddReferencePointer(ip2);
	cout << "��ǰ���ü���: " << ip2 << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
	ReferenceManager::GetInstance()->AddReferencePointer(ip2);
	ReferenceManager::GetInstance()->AddReferencePointer(ip2);
	ReferenceManager::GetInstance()->AddReferencePointer(ip2);
	cout << "��ǰ���ü���: " << ip2 << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
	cout << "=======================" << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip2);
	cout << "��ǰ���ü���: " << ip2 << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip2);
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip2);
	cout << "��ǰ���ü���: " << ip2 << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip2);
	cout << "=======================" << endl;
	cout << "��ǰ���ü���: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
}

// test autopointer with reference manager
void TestAutoPointerWuthReferenceManager()
{
	AutoPointer<A> pa(new A);
	AutoPointer<A> pa1 = pa;
	AutoPointer<A> pa2;
	pa2 = pa;
	cout << pa.GetReferenceCount() << endl;
}

AutoPointer<A> GenerateA()
{
	AutoPointer<A> aa(new A);
	return aa;
}

int main()
{
	//Func();
	//TestReferenceManger();
	TestAutoPointerWuthReferenceManager();
	AutoPointer<A> a = GenerateA(); // �����ƶ����캯������������ΪGenerateA�������������a�����ü���
	cout << a.GetReferenceCount() << endl;
}