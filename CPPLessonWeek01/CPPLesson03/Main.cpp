#include <iostream>
#include <math.h>
#include <iomanip>

// Switch
void Switch()
{
	using namespace std;
	int number = 0;
	cout << "���������֣�" << endl;
	cin >> number;
	
	// switch �����ܵĲ�������ֻ���� int\char\enum �������������͵�ֵ

	switch (number)
	{
	case 1: case 2: case 3:
		cout << "Holle World!" << endl;
		break;
	case 4: case 0: case 5:
		cout << "Say Hello!" << endl;
		break;
	case 7: case 8: case 6:
		cout << "�����������ѽ��" << endl;
		break;
	default:
		cout << "��������" << endl;
		break;
	}

	// ���û��break�������case ��͸
	/*
	switch (number)
	{
	case 1:
		cout << "Holle World!" << endl;
	case 2:
		cout << "Holle World!" << endl;
	default:
		cout << "Holle World!" << endl;

	// numberΪ1ʱ��������� "Hello World��"��numberΪ2ʱ���������"Hello World��"
	*/
}

void ForLoop()
{
	using namespace std;
	cout << "i++ �� ++i û������" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "i = " << i << endl;
	}

	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i;
	}
	cout << "1 ~ 100���ۼӽ����" << sum << endl;
	
	// �Ȳ�����ǰn��͹�ʽ�� n(a1 + an) / 2
	cout << "1 ~ 100���ۼӽ����" << 100 * (1 + 100) / 2 << endl;

	int odd_sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0) continue;
		odd_sum += i;
	}
	cout << "1 ~ 100�������ۼӽ����" << odd_sum << endl;

	// �Ȳ�����ǰn��͹�ʽ�� n(a1 + an) / 2
	cout << "1 ~ 100�������ۼӽ����" << 50 * (1 + 99) / 2 << endl;

	int even_sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (i % 2 != 0) continue;
		even_sum += i;
	}
	cout << "1 ~ 100��ż���ۼӽ����" << even_sum << endl;

	// �Ȳ�����ǰn��͹�ʽ�� n(a1 + an) / 2
	cout << "1 ~ 100��ż���ۼӽ����" << 50 * (2 + 100) / 2 << endl;
}


// ˮ�ɻ�������λ���У���λ������ + ʮλ������ + ��λ������ = ������
void NumberOfDaffodils()
{
	using namespace std;
	int hundreds, ten, single_digit;
	for (int number = 100; number <= 999; number++)
	{
		hundreds = number / 100 % 10; // ��һ�����İ�λ
		ten = number / 10 % 10;		  // ��һ������ʮλ
		single_digit = number % 10;   // ��һ�����ĸ�λ

		// match.h�����pow�������Խ���������
		if (number == pow(hundreds, 3) + pow(ten, 3) + pow(single_digit, 3))
		{
			cout << number << endl;
		}
	}
}

// Ƕ��Forѭ�� 9 * 9 �˷���
void NestedForLoop()
{
	using namespace std;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// iomanip���setw�������Ը�ʽ�����
			cout << setw(2) << i << "*" << j << "=" << i * j << "\t"; // \t��������룬������
		}
		cout << endl;
	}
}


// Forѭ��������1 ����1000���ڵ�����
void ForLoopTest01()
{
	using namespace std;
	for (int i = 2; i <= 1000; i++)
	{
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0) sum += j;
		}
		if (sum == i) cout << i << endl;
	}
}

// Forѭ��������2 ʹ��ѭ����ӡͼ��
void ForLoopTest02()
{
	using namespace std;
	for (int i = 11; i >= 1; i--) {
		if (i % 2 != 0) {
			cout << setw((11 - i) / 2 + 10);
			for (int j = 0; j < i; j++) {
				cout << "*";
			}
			cout << endl;
		}
	}
}

// Forѭ���������test02
void ForLoopTest03()
{
	using namespace std;
	for (int i = 1; i <= 11; i++) {
		if (i % 2 != 0) {
			cout << setw((11 - i) / 2 + 5);
			for (int j = 0; j < i; j++) {
				cout << "*";
			}
			cout << endl;
		}
	}
}

// ��1-100�����ۼӣ���λ��Ϊ3�ı�������Ҫ���룬��ӡ�����
void ForLoopTest04()
{
	using namespace std;
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		//0���κ����ı���
		//if (i % 10 == 0) continue;
		if (i % 10 % 3 == 0) continue;
		sum += i;
	}
	cout << sum << endl;
}

int main()
{
	//Switch();
	//ForLoop();
	//NumberOfDaffodils();
	//NestedForLoop();
	ForLoopTest01();
	ForLoopTest02();
	ForLoopTest03();
	ForLoopTest04();
	system("pause");
}