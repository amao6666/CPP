#include <iostream>
#include <math.h>
#include <iomanip>

// Switch
void Switch()
{
	using namespace std;
	int number = 0;
	cout << "请输入数字：" << endl;
	cin >> number;
	
	// switch 所接受的参数类型只能是 int\char\enum 不能是其他类型的值

	switch (number)
	{
	case 1: case 2: case 3:
		cout << "Holle World!" << endl;
		break;
	case 4: case 0: case 5:
		cout << "Say Hello!" << endl;
		break;
	case 7: case 8: case 6:
		cout << "今天天气真好呀！" << endl;
		break;
	default:
		cout << "输入有误！" << endl;
		break;
	}

	// 如果没有break语句会出现case 穿透
	/*
	switch (number)
	{
	case 1:
		cout << "Holle World!" << endl;
	case 2:
		cout << "Holle World!" << endl;
	default:
		cout << "Holle World!" << endl;

	// number为1时会输出三行 "Hello World！"，number为2时会输出两行"Hello World！"
	*/
}

void ForLoop()
{
	using namespace std;
	cout << "i++ 和 ++i 没有区别" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "i = " << i << endl;
	}

	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i;
	}
	cout << "1 ~ 100的累加结果：" << sum << endl;
	
	// 等差数列前n项和公式： n(a1 + an) / 2
	cout << "1 ~ 100的累加结果：" << 100 * (1 + 100) / 2 << endl;

	int odd_sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0) continue;
		odd_sum += i;
	}
	cout << "1 ~ 100的奇数累加结果：" << odd_sum << endl;

	// 等差数列前n项和公式： n(a1 + an) / 2
	cout << "1 ~ 100的奇数累加结果：" << 50 * (1 + 99) / 2 << endl;

	int even_sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (i % 2 != 0) continue;
		even_sum += i;
	}
	cout << "1 ~ 100的偶数累加结果：" << even_sum << endl;

	// 等差数列前n项和公式： n(a1 + an) / 2
	cout << "1 ~ 100的偶数累加结果：" << 50 * (2 + 100) / 2 << endl;
}


// 水仙花数：三位数中，百位的立方 + 十位的立方 + 个位的立方 = 数本身
void NumberOfDaffodils()
{
	using namespace std;
	int hundreds, ten, single_digit;
	for (int number = 100; number <= 999; number++)
	{
		hundreds = number / 100 % 10; // 求一个数的百位
		ten = number / 10 % 10;		  // 求一个数的十位
		single_digit = number % 10;   // 求一个数的个位

		// match.h库里的pow函数可以进行幂运算
		if (number == pow(hundreds, 3) + pow(ten, 3) + pow(single_digit, 3))
		{
			cout << number << endl;
		}
	}
}

// 嵌套For循环 9 * 9 乘法表
void NestedForLoop()
{
	using namespace std;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// iomanip里的setw函数可以格式化输出
			cout << setw(2) << i << "*" << j << "=" << i * j << "\t"; // \t可以左对齐，很神奇
		}
		cout << endl;
	}
}


// For循环测试题1 计算1000以内的完数
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

// For循环测试题2 使用循环打印图案
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

// For循环正向输出test02
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

// 将1-100的数累加，个位数为3的倍数不需要加入，打印最后结果
void ForLoopTest04()
{
	using namespace std;
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		//0是任何数的倍数
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