#include <iostream>

// ָ��
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

// ��ָ�룬Ұָ��
void NullPtr()
{
	using namespace std;
	int* ptr = nullptr;// C++ 11�����д��
	int* ptr1 = NULL;

	// *ptr // ���ʿ�ָ����׳�����ʱ����

	if (ptr)
	{
		cout << "*ptr = " << *ptr << endl;
	}
	else
	{
		cout << "ptr = nullptr" << endl;
	}

	// Ұָ�룺
	// 1. û�г�ʼ����ָ��
	// 2. �������ڵĵ�ַ��ֵ��ָ�������ָ��
	// 3. ָ��ָ��Ŀռ䱻���գ��ѿռ䣩
	// ��չ��ջ�ռ䣬�ѿռ�
	// 1. ջ�ռ䣬C++�ֲ�����������ջ�ռ䣬��ϵͳ�����ڴ�ͻ����ڴ棬���Ծֲ���������������
	// 2. �ѿռ䣬C++��Ҫ����Ա�ֶ��ڶѿռ�������ռ䣬�ֶ��ͷſռ䣬�������ںͳ�����������ͬ��

	int* iptr = new int; // C++�ڶ������������ֽڿռ䣬�����ؿռ��ַ
	*iptr = 100;         // ��ֵ�������ı����ռ�
	delete iptr;         // C++�ͷŶ����ռ䣬������һ������ָ��

	// cout << *iptr << endl; // �ᱨ����Ϊiptr��Ұָ�룬ָ����ڴ�ռ䱻����
	iptr = nullptr;       // ����ָ��
}

void TestPionter()
{
	using namespace std;

	int ptr[4]{1, 2, 3, 4};
	char ptr2[4]{ '1', '2', '3', '4' };

	cout << sizeof(&ptr) << endl; // 4 16������ ����4�ֽ�
	cout << sizeof(&ptr2) << endl; // 4 16������ ����4�ֽ�

	cout << sizeof(ptr) << endl; // 4 * 4 = 16�����С
	cout << sizeof(ptr2) << endl; // 4 * 1 = 4�����С

	cout << ptr << " == " << &ptr << endl;
}

int main()
{
	//Pointer();
	//NullPtr();
	TestPionter();
	system("pause");
}