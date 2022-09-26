#include <iostream>
#include "User.h"

// 结构体指针
void StructPointer()
{
	using namespace std;
	User user = { "阿毛", 20, "北京" };
	User* uptr = &user;

	// 结构体访问成员变量
	cout << user.name << endl;
	
	// 结构体指针访问成员变量
	cout << uptr->name << endl;
}

void AddUser(User *ptr)
{
	ptr->name = "amao";
	ptr->age = 23;
	ptr->addr = "beijing";
}

void SelectUser(User *ptr)
{
	using namespace std;
	cout << "姓名：" << ptr->name << "\t年龄：" << (*ptr).age << "\t地址：" << ptr->addr << endl;
}

// 指针数组
void ArrayPointer()
{
	using namespace std;
	int numbers[]{ 1, 2, 3, 4, 5, 6 };
	cout << "numbers = " << numbers << endl;
	cout << "numbers + 1 = " << numbers + 1 << endl;
	cout << "numbers + 2 = " << numbers + 2 << endl;
	cout << "numbers + 3 = " << numbers + 3 << endl;
	cout << "numbers + 4 = " << numbers + 4 << endl;
	cout << "numbers + 5 = " << numbers + 5 << endl;

	cout << "========================================" << endl;

	cout << "*numbers = " << *numbers << endl;
	cout << "*(numbers + 1) = " << *(numbers + 1) << endl;
	cout << "*(numbers + 2) = " << *(numbers + 2) << endl;
	cout << "*(numbers + 3) = " << *(numbers + 3) << endl;
	cout << "*(numbers + 4) = " << *(numbers + 4) << endl;
	cout << "*(numbers + 5) = " << *(numbers + 5) << endl;
}

// 指针数组
void PointerArray()
{
	using namespace std;

	int* ptr_array[6]{ nullptr };
	int numbers[]{ 1, 2, 3, 4, 5, 6 };

	for (int i = 0; i < 6; i++)
	{
		cout << ptr_array[i] << endl;
	}

	cout << "=======================================================" << endl;

	for (int i = 0; i < 6; i++)
	{
		ptr_array[i] = numbers + i;
	}

	cout << "=======================================================" << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << "ptr_array[" << i << "] = " << ptr_array[i] << endl;
	}

	cout << "=======================================================" << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << "*ptr_array[" << i << "] = " << *ptr_array[i] << endl;
	}
}

User* user_ptr_array[6]{ nullptr };
int user_size = 0;
// 结构体类型的指针数组
void PointerOfStructArray()
{
	using namespace std;
	string name = " ";
	int age = 0;
	string addr = " ";

	cout << "姓名：";
	cin >> name;
	cout << "年龄：";
	cin >> age;
	cout << "地址：";
	cin >> addr;

	User* user_ptr = new User; //在堆区申请User空间，并返回地址
	user_ptr->name = name;
	user_ptr->age = age;
	user_ptr->addr = addr;

	user_ptr_array[user_size] = user_ptr;
	user_size++;
}

void DisplayAllUser()
{
	for (int i = 0; i < user_size; i++)
	{
		SelectUser(user_ptr_array[i]);
	}
}

// 行指针，数组指针
void PointerOfArray()
{
	using namespace std;
	int numbers[3][4] = { {1, 2, 3, 4}, {11, 22, 33, 44} };
	int* ptr1 = numbers[0]; // 只是一个简单的数组指针
	int(*ptr2)[4] = numbers + 1; // 必须声明指针的类型是个数组，但是指针地址仍然是4个字节，纯纯的为了声明的时候表明指针指向的是数组。
	int(*ptr3)[4] = numbers; // 不能简单的作为指针赋值给指针变量，必须提前声明指针类型是数组

	cout << "sizeof(ptr1) = " << sizeof(ptr1) << endl;
	cout << "sizeof(ptr2) = " << sizeof(ptr2) << endl;
	cout << "ptr1[0] = " << ptr1[0] << endl;
	cout << "(*ptr2)[1] = " << (*ptr2)[1] << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << (*ptr3)[j] << endl;
		}
		ptr3++;
	}
}

int CallBack(int, int);

// 默认参数只能使用函数声明时。当使用函数指针取其地址时，默认参数也是不可见的。

// 函数指针
void PointerOfFunc(int(*cbptr)(int, int))
{
	(*cbptr)(1234, 4);
}


void Apply()
{
	User user;
	/*AddUser(&user);
	SelectUser(&user);
	ArrayPointer();
	PointerArray();*/

	/*PointerOfStructArray();
	PointerOfStructArray();
	PointerOfStructArray();
	DisplayAllUser();*/

	//PointerOfArray();
	int(*cbptr)(int, int) = CallBack;
	PointerOfFunc(cbptr);
}

int main()
{
	//StructPointer();
	Apply();
	system("pause");
}

int CallBack(int a, int b)
{
	using namespace std;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 123;
}