#include <iostream>

// 内联函数(声明和定义都要加inline关键字)：
//	1. 在编译时会将函数体内的逻辑复制到内联函数被调用的地方
//	2. 内联函数会减少函数调用时的性能损耗，同时也会增加函数体被多次复制的内存占用

inline void InlineFunc()
{
	using namespace std;
	cout << "I am inline func." << endl;
}

// 宏：
//	1. 提高代码段的复用
//	2. 在编译时期，会将宏翻译成代码段进行编译

#define _COUT cout <<

void MacroFunc()
{
	using namespace std;
	_COUT "I am a MacroFunc" << endl;
}

#undef _COUT // 卸载宏，之后的代码就不能使用_COUT

// 带参数的宏：
//	1. 宏的参数并不是真实的数据，实际上也是将代码片段传入宏的内部
#define _MULTI(a, b) a * b
//	2. 避免运算优先级的问题，尽量给参数加括号
#define _MAX(a, b) (((a) > (b)) ? (a) : (b))

void MarcoFuncWithArgs()
{
	using namespace std;

	// 此处编译后的结果相当于！！！！！
	// cout << 10 + 10 * 10 << endl;
	cout << _MULTI(10 + 10, 10) << endl;

	cout << _MAX(10 + 10, 10) << endl;
}

// 数据类型别名
//	1. typedef 原类型 别名

void Alias()
{
	using namespace std;
	struct User { string name; int age; int sex; };
	// 基础数据类型别名
	typedef int _INT;
	_INT a = 0;

	// 结构体别名
	typedef User _USER;
	_USER user = { "amao", 25, 1 };

	// 函数指针别名
	typedef void(*_FUNCPTR)(void);
	_FUNCPTR alias_ptr = Alias;
}

// 引用
// 1. 引用又称为变量的别名，使用比指针方便
void QuoteArgs(int &quote)
{
	quote = 2022;
}

void Quote()
{
	using namespace std;
	int i = 123;
	QuoteArgs(i);
	int& ii = i; // 引用的行为基本和变量行为一致
	cout << ii << endl;

	string str = "1000";
	const string& iii = str;
	const string* iptr = &iii;

	str = "2000"; // 给str赋值依然可以影响常量 iii 的值！！！！
	//iii = "3000"; 不可以给常量赋值

	cout << str << endl;
	cout << iii << endl;
	cout << "sizeof(&iii)" << sizeof(iii) << endl;
	cout << "sizeof(*iii)" << sizeof(iptr) << endl;

	//int iiii = 1000;
	//const int& iiiii = 1000;
	//int arrays[iiiii]; //常量引用不能作为数组声明时的长度参数

	//const int iiii = 1000;
	//const int* iiiii = &iiii;
	//*iiiii = 1001; // 使用指针也不能修改常量

	// 右值引用，限制引用对象必须是值
	//int&& i = 123;
	//i = 456;// 右值引用依然可以赋值，只是限制了引用对象必须是右值
}

// 命名空间
namespace abc
{
	using namespace std;
	string name = "";
	void NamespaceFunc()
	{
		cout << "I am a NamespaceFunc." << endl;
	}
}

//随机数
#include <ctime>
void GetRandomValue()
{
	using namespace std;
	srand((unsigned int)time(NULL));//重置随机种子，time(NULL)返回当前系统秒数
	int rand1 = rand();
	int rand2 = rand();
	cout << rand1 << endl;
	cout << rand2 << endl;
}

int main()
{
	void(*InlinefuncPtr)(void) = InlineFunc;
	(*InlinefuncPtr)();
	MacroFunc();
	MarcoFuncWithArgs();
	Quote();
	using namespace abc;
	NamespaceFunc();
	
	//假随机 因为time(NULL)返回系统秒数，三次随机种子大概率不变
	GetRandomValue();
	GetRandomValue();
	GetRandomValue();

	system("pause");
}