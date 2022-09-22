#include <iostream>

// 指针
void Pointer()
{
	using namespace std;
	int number = 100;
	int* ip = &number;

	cout << "number = " << number << endl;
	cout << "&number = " << &number << endl;
	cout << "ip = " << ip << endl;
	cout << "*ip = " << *ip << endl;
	*ip = 500;
	cout << "*ip = 500; number = " << number << endl;
}

// 空指针，野指针
void NullPtr()
{
	using namespace std;
	int* ptr = nullptr;// C++ 11后的新写法
	int* ptr1 = NULL;

	// *ptr // 访问空指针会抛出运行时报错

	if (ptr)
	{
		cout << "*ptr = " << *ptr << endl;
	}
	else
	{
		cout << "ptr = nullptr" << endl;
	}

	// 野指针：
	// 1. 没有初始化的指针
	// 2. 将不存在的地址赋值给指针变量的指针
	// 3. 指针指向的空间被回收（堆空间）
	// 扩展：栈空间，堆空间
	// 1. 栈空间，C++局部变量申请在栈空间，由系统申请内存和回收内存，所以局部变量有生命周期
	// 2. 堆空间，C++需要程序员手动在堆空间内申请空间，手动释放空间，生命周期和程序运行周期同步

	int* iptr = new int; // C++在堆区内申请四字节空间，并返回空间地址
	*iptr = 100;         // 赋值给堆区的变量空间
	delete iptr;         // C++释放堆区空间，参数是一个堆区指针

	// cout << *iptr << endl; // 会报错，因为iptr是野指针，指向的内存空间被回收
	iptr = nullptr;       // 回收指针
}

void TestPionter()
{
	using namespace std;

	int ptr[4]{1, 2, 3, 4};
	char ptr2[4]{ '1', '2', '3', '4' };

	cout << sizeof(&ptr) << endl; // 4 16进制数 所以4字节
	cout << sizeof(&ptr2) << endl; // 4 16进制数 所以4字节

	cout << sizeof(ptr) << endl; // 4 * 4 = 16数组大小
	cout << sizeof(ptr2) << endl; // 4 * 1 = 4数组大小

	cout << ptr << " == " << &ptr << endl;
}

int main()
{
	//Pointer();
	//NullPtr();
	TestPionter();
	system("pause");
}