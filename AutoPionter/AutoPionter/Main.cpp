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

//借助泛型编程让一个类托管所有类型的空间
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

	cout << "借助模板类管理所有类的空间" << endl;

	A* pa1 = new A;
	Temp<A> tp;
	tp.pt = pa1;*/

	//A* pa = new A;
	//AutoPointer<A> ap(pa);

	AutoPointer<A> ap(new A);
	// 测试模板成员函数指针
	TempFuncPtr(new A, &A::SayHello);

	// 通过重载指针运算符简化逻辑
	ap->SayHello();
	(*ap).SayHello();
	if (ap)
	{
		cout << "Ap type is Bool" << endl;
	}
}

// 静态成员属性必须类外初始化
ReferenceManager* ReferenceManager::_instance = nullptr;
void TestReferenceManger()
{
	int* ip = new int;

	ReferenceManager::GetInstance()->AddReferencePointer(ip);
	cout << "当前引用计数: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;
	ReferenceManager::GetInstance()->AddReferencePointer(ip);
	ReferenceManager::GetInstance()->AddReferencePointer(ip);
	ReferenceManager::GetInstance()->AddReferencePointer(ip);
	cout << "当前引用计数: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;
	cout << "=======================" << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip);
	cout << "当前引用计数: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip);
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip);
	cout << "当前引用计数: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip);
	cout << "=======================" << endl;
	//cout << "当前引用计数: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip) << endl;

	int* ip2 = new int;
	ReferenceManager::GetInstance()->AddReferencePointer(ip2);
	cout << "当前引用计数: " << ip2 << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
	ReferenceManager::GetInstance()->AddReferencePointer(ip2);
	ReferenceManager::GetInstance()->AddReferencePointer(ip2);
	ReferenceManager::GetInstance()->AddReferencePointer(ip2);
	cout << "当前引用计数: " << ip2 << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
	cout << "=======================" << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip2);
	cout << "当前引用计数: " << ip2 << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip2);
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip2);
	cout << "当前引用计数: " << ip2 << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
	ReferenceManager::GetInstance()->RemoveReferencePointer(ip2);
	cout << "=======================" << endl;
	cout << "当前引用计数: " << ip << "count: " << ReferenceManager::GetInstance()->GetPointerCount(ip2) << endl;
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
	AutoPointer<A> a = GenerateA(); // 会走移动构造函数，并不会因为GenerateA函数结束后回收a的引用计数
	cout << a.GetReferenceCount() << endl;
}