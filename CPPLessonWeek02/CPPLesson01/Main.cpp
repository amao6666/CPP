#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

/*
#include 的两种导入头文件的方式
 <>尖括号用于导入C++库文件
 ""双引号用于导入用户自定义头文件，如果没有找到用户自定义头文件则去找C++库文件
*/

// 实参，形参，默认参
//1. 函数调用时传入的参数被称为实参。
//2. 函数声明或定义时需要接收的参数被称为形参，形参属于函数内部，为函数的局部变量。
//   函数声明时可以忽略形参的参数名，但必须声明形参的类型。
//3. 默认参数只能放在参数列表的末尾。


// 函数重载
// 函数名相同，参数列表的数据类型不同（和参数名没有关系），通过传入的实参执行不同的逻辑，*函数返回值和重载没关系。
// C++处理多数据类型形参的解决方案。感觉有点Low！！！！


// 重载
std::string Func01()
{
	return "12";
}

int Func01(int b)
{
	return b;
}

// 函数参数传递方式
// 1. 值传递，形参得到的是值的拷贝
// 2. 地址传递， 形参得到的是地址
// 

void ValueArgs(int a)
{
	a++;
}

// 数组的名字是数组的地址
void AddrArgs(int numbers[])
{
	using namespace std;
	int new_numbers[5]{ 0, 0, 0, 0, 0 };
	//numbers = new_numbers; // numbers 是实参地址的拷贝，对其赋值并不会影响实参
	numbers[0] = 1234; // 会影响实参的数据
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
	// ios::out 打开文件并把文件指针放置到文件开头。所以后面的写入会覆盖内容
	// ios::app 打开文件并把文件指针放置到文件末尾。所以后面的写入会追加到文件末尾
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

	// 1. 使用char数组作为容器
	cout << "1. 使用char数组作为容器" << endl;
	char DataArray[1024]{};
	// 最后会将换行填充到 DataArray 但是会暂停While循环
	while (ifs >> DataArray)
	{
		// ifs >> DataArray 相当于把每行读出的内容填充到数组中
		// 每次填充前会清空Buffer数组
		cout << DataArray << endl;
	}

	// 最后会清空buffer数组
	cout << "DataArray: " << DataArray << endl;
	cout << "DataArray[0]: " << DataArray[0] << endl;
	ifs.close();

	// 2. 使用string当作Buffer
	cout << "2. 使用string当作Buffer" << endl;
	ifs.open("Data.txt", ios::in);
	string buffer;
	// string 最后一次换行并没有被填充到string buffer
	while (ifs >> buffer)
	{
		// 会覆盖string原来的值
		cout << buffer << endl;
	}

	// 并不会将最后一行的数据清空，！！！离大谱！！！跟char数组竟然不一样
	cout << "buffer: " << buffer << endl;
	cout << "buffer[0]: " << buffer[0] << endl;
	ifs.close();

	// 3. 使用ifs.getline
	cout << "3. 使用ifs.getline" << endl;
	ifs.open("Data.txt", ios::in);
	char cahr_array[1024]{};
	while (ifs.getline(cahr_array, sizeof(buffer)))
	{
		// 会覆盖cahr_array原来的值
		cout << cahr_array << endl;
	}
	// 不会保留最后一行，cahr_array会被清空！！！
	cout << "cahr_array: " << cahr_array << endl;
	cout << "cahr_array[0]: " << cahr_array[0] << endl;
	ifs.close();

	// 4. 使用string.getline
	cout << "4. 使用string.getline" << endl;
	ifs.open("Data.txt", ios::in);
	string buffer1;
	// string.getline最后也会把换行填充到string buffer1
	while (getline(ifs, buffer1))
	{
		// 会覆盖buffer1原来的值
		cout << buffer1 << endl;
	}
	// 不会保留最后一行，buffer会被清空！！！又离大谱！！！
	cout << "buffer1: " << buffer1 << endl;
	cout << "buffer1[0]: " << buffer1[0] << endl;
	ifs.close();

	// 5. 使用ifs.eof判断是否读到文件结尾
	cout << "5. 使用ifs.eof判断是否读到文件结尾" << endl;
	ifs.open("Data.txt", ios::in);
	string buffer2;
	while (!ifs.eof())
	{
		// 因为有最后一行换行，所以会多打印一次buffer2，又因为string会忽略换行符所以buffer2会保留最后一行的数据
		ifs >> buffer2;
		// 会覆盖buffer1原来的值
		cout << buffer2 << endl;
	}
	// 不会保留最后一行，buffer会被清空！！！又离大谱！！！
	cout << "buffer2: " << buffer2 << endl;
	cout << "buffer2[0]: " << buffer2[0] << endl;
	ifs.close();
}

void WriteUserToLocalFile()
{
	using namespace std;
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	cout << "请输入年龄：" << endl;
	int age;
	cin >> age;
	cout << "请输入住址：" << endl;
	string addr;
	cin >> addr;

	// 将数据写入文件
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
	// ifs >> 会根据每行的空格拆分数据
	while (!ifs.eof() && ifs >> buffer)
	{
		ifs >> name; ifs >> age; ifs >> addr;
		cout << "姓名：" << name;
		cout << "\t年龄：" << age;
		cout << "\t住址：" << addr << endl;
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