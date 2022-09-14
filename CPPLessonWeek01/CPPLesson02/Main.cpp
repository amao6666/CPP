#include <iostream>
#include <iomanip>

// 整型
void Integer()
{
	using namespace std;
	// short
	// 有符号short 2字节 16位 -2^15 ~ 2^15-1
	short a = 0;
	cout << "short size：" << sizeof(short) << endl;
	cout << "有符号short取值范围 MIN：" << SHRT_MIN << "  MAX：" << SHRT_MAX << endl;

	// 无符号short 2字节 16位 0 ~ 2^16 - 1
	unsigned short b = 0;
	cout << "无符号short取值范围 MIN：" << 0 << "  MAX：" << USHRT_MAX << endl;
	// 无符号整型如果赋值为负数会自动转成正数
	b = -1;
	cout << "无符号short -1：" << b << endl;

	// int
	// 有符号int 4字节 32位 -2^31 ~ 2^31 -1
	cout << "int size：" << sizeof(int) << endl;
	cout << "有符号int取值范围 MIN：" << INT_MIN << "  MAX：" << INT_MAX << endl;
	cout << "无符号int取值范围 MIN：" << 0 << "  MAX：" << UINT_MAX << endl;

	// long
	// Windows 操作系统不管32位和64位都是4字节
	// Linux 操作系统下32位占4字节，64位占8字节
	cout << "long size：" << sizeof(long) << endl;
	cout << "有符号long取值范围 MIN：" << LONG_MIN << "  MAX：" << LONG_MAX << endl;
	cout << "无符号long取值范围 MIN：" << 0 << "  MAX：" << ULONG_MAX << endl;

	// long long
	// 所有系统都占8字节
	long long ll = 0;
	cout << "long long size：" << sizeof(long long) << endl;
	cout << "有符号long long取值范围 MIN：" << LLONG_MIN << "  MAX：" << LLONG_MAX << endl;
	cout << "无符号long long取值范围 MIN：" << 0 << "  MAX：" << ULLONG_MAX << endl;
}

// 字符型
void Char()
{
	using namespace std;
	// char 占1字节 string在C++里可以理解为char的集合并不是数据类型
	// 汉字，韩语，日语占两个字节
	char c0 = 'a';
	// char c1 = '好'; //报错

	// ASCALL码
	// 1字节 8位 可以表示 0 ~ 2^7-1字符，每个数字对应一个字符，数字就是对应字符的ASCLL码
	char c2 = 'A';
	// C++里char和int做 == 时会先转成ASCLL码再做比较
	if (c2 == 65) {
		cout << "A == 65：" << c2 << endl;
	}
	else
	{
		cout << "char A：" << c2 << endl;
	}
}

// 布尔型
void Boolean()
{
	using namespace std;
	// 非假即为
	int b = 1000;
	if (b) {

	}
	// ture == 1 false == 0
	cout << "true = " << true << endl;
	cout << "false = " << false << endl;
}

// 浮点型
void Float()
{
	using namespace std;
	// 浮点型必须加f后缀，不然默认会是double类型
	float f = 12.34567f;
	double d = 12.345678;

	
	// float 4字节
	cout << "float size：" << sizeof(float) << endl;
	// double 8字节
	cout << "double size：" << sizeof(double) << endl;
	// 有效位数，小数点前后所有位数
	// float有效位数7位，double有效位数15~16位
	//cout 输出时会缺少位数，可以用 iomanip::setprecision 解决
	cout << setprecision(7) << f << endl;
}

// 数据类型
int main()
{
	Integer();
	Char();
	Boolean();
	Float();
	system("pause");
}