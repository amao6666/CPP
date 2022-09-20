#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

/*
#include �����ֵ���ͷ�ļ��ķ�ʽ
 <>���������ڵ���C++���ļ�
 ""˫�������ڵ����û��Զ���ͷ�ļ������û���ҵ��û��Զ���ͷ�ļ���ȥ��C++���ļ�
*/

// ʵ�Σ��βΣ�Ĭ�ϲ�
//1. ��������ʱ����Ĳ�������Ϊʵ�Ρ�
//2. ������������ʱ��Ҫ���յĲ�������Ϊ�βΣ��β����ں����ڲ���Ϊ�����ľֲ�������
//   ��������ʱ���Ժ����βεĲ������������������βε����͡�
//3. Ĭ�ϲ���ֻ�ܷ��ڲ����б��ĩβ��


// ��������
// ��������ͬ�������б���������Ͳ�ͬ���Ͳ�����û�й�ϵ����ͨ�������ʵ��ִ�в�ͬ���߼���*��������ֵ������û��ϵ��
// C++��������������βεĽ���������о��е�Low��������


// ����
std::string Func01()
{
	return "12";
}

int Func01(int b)
{
	return b;
}

// �����������ݷ�ʽ
// 1. ֵ���ݣ��βεõ�����ֵ�Ŀ���
// 2. ��ַ���ݣ� �βεõ����ǵ�ַ
// 

void ValueArgs(int a)
{
	a++;
}

// ���������������ĵ�ַ
void AddrArgs(int numbers[])
{
	using namespace std;
	int new_numbers[5]{ 0, 0, 0, 0, 0 };
	//numbers = new_numbers; // numbers ��ʵ�ε�ַ�Ŀ��������丳ֵ������Ӱ��ʵ��
	numbers[0] = 1234; // ��Ӱ��ʵ�ε�����
	cout << numbers[0] << endl;
}

void TestArgs()
{
	using namespace std;
	cout << "Func01:" << Func01() << endl;
	cout << "Func01:" << Func01(1234) << endl;
	int a = 1;
	ValueArgs(a);
	cout << "a = " << a << endl;
	int numbers[4];
	AddrArgs(numbers);
	cout << "numbers[0] = " << numbers[0] << endl;
}

void WriteDataToLocal()
{
	using namespace std;
	ofstream ofs;
	// ios::out ���ļ������ļ�ָ����õ��ļ���ͷ�����Ժ����д��Ḳ������
	// ios::app ���ļ������ļ�ָ����õ��ļ�ĩβ�����Ժ����д���׷�ӵ��ļ�ĩβ
	ofs.open("Data.txt", ios::out);
	ofs << "123" << endl;
	ofs << "456" << endl;
	ofs << "789" << endl;
	ofs.close();
}

void ReadDataFromLocal()
{
	using namespace std;
	ifstream ifs;
	ifs.open("Data.txt", ios::in);

	// 1. ʹ��char������Ϊ����
	cout << "1. ʹ��char������Ϊ����" << endl;
	char DataArray[1024]{};
	// ���Ὣ������䵽 DataArray ���ǻ���ͣWhileѭ��
	while (ifs >> DataArray)
	{
		// ifs >> DataArray �൱�ڰ�ÿ�ж�����������䵽������
		// ÿ�����ǰ�����Buffer����
		cout << DataArray << endl;
	}

	// �������buffer����
	cout << "DataArray: " << DataArray << endl;
	cout << "DataArray[0]: " << DataArray[0] << endl;
	ifs.close();

	// 2. ʹ��string����Buffer
	cout << "2. ʹ��string����Buffer" << endl;
	ifs.open("Data.txt", ios::in);
	string buffer;
	// string ���һ�λ��в�û�б���䵽string buffer
	while (ifs >> buffer)
	{
		// �Ḳ��stringԭ����ֵ
		cout << buffer << endl;
	}

	// �����Ὣ���һ�е�������գ�����������ף�������char���龹Ȼ��һ��
	cout << "buffer: " << buffer << endl;
	cout << "buffer[0]: " << buffer[0] << endl;
	ifs.close();

	// 3. ʹ��ifs.getline
	cout << "3. ʹ��ifs.getline" << endl;
	ifs.open("Data.txt", ios::in);
	char cahr_array[1024]{};
	while (ifs.getline(cahr_array, sizeof(buffer)))
	{
		// �Ḳ��cahr_arrayԭ����ֵ
		cout << cahr_array << endl;
	}
	// ���ᱣ�����һ�У�cahr_array�ᱻ��գ�����
	cout << "cahr_array: " << cahr_array << endl;
	cout << "cahr_array[0]: " << cahr_array[0] << endl;
	ifs.close();

	// 4. ʹ��string.getline
	cout << "4. ʹ��string.getline" << endl;
	ifs.open("Data.txt", ios::in);
	string buffer1;
	// string.getline���Ҳ��ѻ�����䵽string buffer1
	while (getline(ifs, buffer1))
	{
		// �Ḳ��buffer1ԭ����ֵ
		cout << buffer1 << endl;
	}
	// ���ᱣ�����һ�У�buffer�ᱻ��գ�����������ף�����
	cout << "buffer1: " << buffer1 << endl;
	cout << "buffer1[0]: " << buffer1[0] << endl;
	ifs.close();

	// 5. ʹ��ifs.eof�ж��Ƿ�����ļ���β
	cout << "5. ʹ��ifs.eof�ж��Ƿ�����ļ���β" << endl;
	ifs.open("Data.txt", ios::in);
	string buffer2;
	while (!ifs.eof())
	{
		// ��Ϊ�����һ�л��У����Ի���ӡһ��buffer2������Ϊstring����Ի��з�����buffer2�ᱣ�����һ�е�����
		ifs >> buffer2;
		// �Ḳ��buffer1ԭ����ֵ
		cout << buffer2 << endl;
	}
	// ���ᱣ�����һ�У�buffer�ᱻ��գ�����������ף�����
	cout << "buffer2: " << buffer2 << endl;
	cout << "buffer2[0]: " << buffer2[0] << endl;
	ifs.close();
}

void WriteUserToLocalFile()
{
	using namespace std;
	cout << "������������" << endl;
	string name;
	cin >> name;
	cout << "���������䣺" << endl;
	int age;
	cin >> age;
	cout << "������סַ��" << endl;
	string addr;
	cin >> addr;

	// ������д���ļ�
	ofstream ofs;
	ofs.open("UserInfo.txt", ios::out);
	ofs << name << " ";
	ofs << age << " ";
	ofs << addr << endl;
	ofs.close();
}

void ReadUserFromLocalFile()
{
	using namespace std;
	ifstream ifs;
	string name;
	int age;
	string addr;
	ifs.open("UserInfo.txt", ios::in);
	char buffer[1024];
	// ifs >> �����ÿ�еĿո�������
	while (!ifs.eof() && ifs >> buffer)
	{
		ifs >> name; ifs >> age; ifs >> addr;
		cout << "������" << name;
		cout << "\t���䣺" << age;
		cout << "\tסַ��" << addr << endl;
	}
	ifs.close();
}

int main()
{
	//TestArgs();
	//WriteDataToLocal();
	//ReadDataFromLocal();
	WriteUserToLocalFile();
	ReadUserFromLocalFile();
	system("pause");
}