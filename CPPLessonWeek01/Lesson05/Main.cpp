#include <iostream>
#include <string>
#include <Windows.h>

struct Person
{
	std::string name;
	int age;
	int ID;
	int password;
};

void Struct()
{
	using namespace std;
	// 结构体的拷贝

	Person p1 = { "小红", 0, 0, 666666 };
	Person p2 = p1;
	cout << p1.name << endl;
	cout << p2.name << endl;
	p1.name = "小绿";
	cout << p1.name << endl;
	// 结构体深拷贝
	cout << p2.name << endl;

	Person ps[]{ p1 };
	ps[0].name = "小黑";
	cout << ps[0].name << endl;
}

int * TestArray(int i)
{
	using namespace std;
	int numbers[5]{1, i, 3, 4, 5};
	cout << numbers << endl;
	

	return numbers;
}
void test() 
{
	using namespace std;
	int a = 100;
	cout << &a << endl;
}

void test1()
{
	// 在同一个作用域内的两个相同方法内的局部变量复用地址
	// 巨坑 ！！！！！
	test();
	test();
}
int main()
{
	using namespace std;
	//Struct();

	// 局部变量在函数结束后会被释放
	int *numbers1;
	int *numbers2;
	test();
	cout << "===============" << endl;
	test1();
	numbers1 = TestArray(2);
	cout << *(numbers1 + 1) << endl;
	numbers2 = TestArray(3);
	cout << *(numbers1 + 1) << endl;
	cout << *(numbers2 + 1) << endl;
	
	system("pause");
}