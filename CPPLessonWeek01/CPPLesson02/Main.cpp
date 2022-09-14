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
	// 非假即为真
	int b = 1000;
	if (b) {
		cout << "非假即为真";
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


// 算数运算符
void ArithmeticOperators()
{
	using namespace std;
	// 除法 /
	int i = 100;
	int b = 100 / 3;
	float f = 100 / 3.0f;
	// 注意除法返回结果的类型
	cout << "int 100 / 3 = 整数" << b << endl;
	cout << "float 100 / 3 = 浮点数" << f << endl;

	// % 取余
	// 取余常用于计算行和列，以及固定次数后执行一次操作
	// 除法和取余 后面的运算数为0时会导致运行时报错

	// ++ --
	//	1. 后置++，先执行当前行的其他逻辑，再执行++逻辑
	i = 100;
	cout << "后置++，先执行cout再执行++：" << i++ << endl;
	//	2. 前置++，先执行++逻辑再执行当前行逻辑
	i = 100;
	cout << "前置++，先执行++再执行cout：" << ++i << endl;
}

// 三元运算符
void TernaryOperation()
{
	using namespace std;
	int i = 0;
	cout << "int i = 0;" << endl;
	i == 0 ? i = 1 : i = 2;
	cout << "三元运算：i == 0 ？ i = 1 ： i= 2 结果：" << i << endl;

	// 三元运算的嵌套
	string res = i == 0 ? "i为0" : i < 0 ? "i小于0" : "i大于0";
	cout << "三元嵌套：i == 0 ? i为0 : i < 0 ? i小于0 : i大于0  结果：" << res << endl;
}

// 流程控制
void IfElse()
{
	// 逻辑体内只有一行逻辑时可以省略大括号
	int a = 0;
	if (a == 0) a = 1;
	// 建议换行
	if (a == 0)
		a = 1;
	else
		a = 0;
}

// 数据类型
int main()
{
	Integer();
	Char();
	Boolean();
	Float();
	ArithmeticOperators();
	TernaryOperation();
	system("pause");
}