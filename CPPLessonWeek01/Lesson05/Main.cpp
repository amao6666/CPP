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
	// �ṹ��Ŀ���

	Person p1 = { "С��", 0, 0, 666666 };
	Person p2 = p1;
	cout << p1.name << endl;
	cout << p2.name << endl;
	p1.name = "С��";
	cout << p1.name << endl;
	// �ṹ�����
	cout << p2.name << endl;

	Person ps[]{ p1 };
	ps[0].name = "С��";
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
	// ��ͬһ���������ڵ�������ͬ�����ڵľֲ��������õ�ַ
	// �޿� ����������
	test();
	test();
}
int main()
{
	using namespace std;
	//Struct();

	// �ֲ������ں���������ᱻ�ͷ�
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