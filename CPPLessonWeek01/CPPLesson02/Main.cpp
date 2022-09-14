#include <iostream>
#include <iomanip>

// ����
void Integer()
{
	using namespace std;
	// short
	// �з���short 2�ֽ� 16λ -2^15 ~ 2^15-1
	short a = 0;
	cout << "short size��" << sizeof(short) << endl;
	cout << "�з���shortȡֵ��Χ MIN��" << SHRT_MIN << "  MAX��" << SHRT_MAX << endl;

	// �޷���short 2�ֽ� 16λ 0 ~ 2^16 - 1
	unsigned short b = 0;
	cout << "�޷���shortȡֵ��Χ MIN��" << 0 << "  MAX��" << USHRT_MAX << endl;
	// �޷������������ֵΪ�������Զ�ת������
	b = -1;
	cout << "�޷���short -1��" << b << endl;

	// int
	// �з���int 4�ֽ� 32λ -2^31 ~ 2^31 -1
	cout << "int size��" << sizeof(int) << endl;
	cout << "�з���intȡֵ��Χ MIN��" << INT_MIN << "  MAX��" << INT_MAX << endl;
	cout << "�޷���intȡֵ��Χ MIN��" << 0 << "  MAX��" << UINT_MAX << endl;

	// long
	// Windows ����ϵͳ����32λ��64λ����4�ֽ�
	// Linux ����ϵͳ��32λռ4�ֽڣ�64λռ8�ֽ�
	cout << "long size��" << sizeof(long) << endl;
	cout << "�з���longȡֵ��Χ MIN��" << LONG_MIN << "  MAX��" << LONG_MAX << endl;
	cout << "�޷���longȡֵ��Χ MIN��" << 0 << "  MAX��" << ULONG_MAX << endl;

	// long long
	// ����ϵͳ��ռ8�ֽ�
	long long ll = 0;
	cout << "long long size��" << sizeof(long long) << endl;
	cout << "�з���long longȡֵ��Χ MIN��" << LLONG_MIN << "  MAX��" << LLONG_MAX << endl;
	cout << "�޷���long longȡֵ��Χ MIN��" << 0 << "  MAX��" << ULLONG_MAX << endl;
}

// �ַ���
void Char()
{
	using namespace std;
	// char ռ1�ֽ� string��C++��������Ϊchar�ļ��ϲ�������������
	// ���֣��������ռ�����ֽ�
	char c0 = 'a';
	// char c1 = '��'; //����

	// ASCALL��
	// 1�ֽ� 8λ ���Ա�ʾ 0 ~ 2^7-1�ַ���ÿ�����ֶ�Ӧһ���ַ������־��Ƕ�Ӧ�ַ���ASCLL��
	char c2 = 'A';
	// C++��char��int�� == ʱ����ת��ASCLL�������Ƚ�
	if (c2 == 65) {
		cout << "A == 65��" << c2 << endl;
	}
	else
	{
		cout << "char A��" << c2 << endl;
	}
}

// ������
void Boolean()
{
	using namespace std;
	// �Ǽټ�Ϊ
	int b = 1000;
	if (b) {

	}
	// ture == 1 false == 0
	cout << "true = " << true << endl;
	cout << "false = " << false << endl;
}

// ������
void Float()
{
	using namespace std;
	// �����ͱ����f��׺����ȻĬ�ϻ���double����
	float f = 12.34567f;
	double d = 12.345678;

	
	// float 4�ֽ�
	cout << "float size��" << sizeof(float) << endl;
	// double 8�ֽ�
	cout << "double size��" << sizeof(double) << endl;
	// ��Чλ����С����ǰ������λ��
	// float��Чλ��7λ��double��Чλ��15~16λ
	//cout ���ʱ��ȱ��λ���������� iomanip::setprecision ���
	cout << setprecision(7) << f << endl;
}

// ��������
int main()
{
	Integer();
	Char();
	Boolean();
	Float();
	system("pause");
}