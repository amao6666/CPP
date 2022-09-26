#include <iostream>
#include "User.h"

// �ṹ��ָ��
void StructPointer()
{
	using namespace std;
	User user = { "��ë", 20, "����" };
	User* uptr = &user;

	// �ṹ����ʳ�Ա����
	cout << user.name << endl;
	
	// �ṹ��ָ����ʳ�Ա����
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
	cout << "������" << ptr->name << "\t���䣺" << (*ptr).age << "\t��ַ��" << ptr->addr << endl;
}

// ָ������
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

// ָ������
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
// �ṹ�����͵�ָ������
void PointerOfStructArray()
{
	using namespace std;
	string name = " ";
	int age = 0;
	string addr = " ";

	cout << "������";
	cin >> name;
	cout << "���䣺";
	cin >> age;
	cout << "��ַ��";
	cin >> addr;

	User* user_ptr = new User; //�ڶ�������User�ռ䣬�����ص�ַ
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

// ��ָ�룬����ָ��
void PointerOfArray()
{
	using namespace std;
	int numbers[3][4] = { {1, 2, 3, 4}, {11, 22, 33, 44} };
	int* ptr1 = numbers[0]; // ֻ��һ���򵥵�����ָ��
	int(*ptr2)[4] = numbers + 1; // ��������ָ��������Ǹ����飬����ָ���ַ��Ȼ��4���ֽڣ�������Ϊ��������ʱ�����ָ��ָ��������顣
	int(*ptr3)[4] = numbers; // ���ܼ򵥵���Ϊָ�븳ֵ��ָ�������������ǰ����ָ������������

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

// Ĭ�ϲ���ֻ��ʹ�ú�������ʱ����ʹ�ú���ָ��ȡ���ַʱ��Ĭ�ϲ���Ҳ�ǲ��ɼ��ġ�

// ����ָ��
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