#include <iostream>
#include <vector>

void WhileLoop()
{
	using namespace std;
	int year = 0;
	float money = 2000.0f;

	while (money < 4000)
	{
		money *= 1.025f;
		year++;
	}
	cout << year << "年后2000会变" << money << endl;
}

// 无视规则跳转逻辑
void Goto()
{
	using namespace std;
FLAG:
	cout << 1 << endl;
	goto FLAG;
	cout << 2 << endl;
}

// 冒泡排序
void Sort01()
{
	using namespace std;
	int numbers[]{ 2, 3, 6, 1, 29, 32, 12, 33 };
	int numbers_size = sizeof(numbers) / sizeof(int);
	for (int i = 0; i < numbers_size ; i++)
	{
		for (int j = 0; j < numbers_size - i - 1; j++)
		{
			if (numbers[j] > numbers[j + 1]) {
				int temp_num = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp_num;
			}
		}
	}
	for (int n : numbers) cout << n << ",";
	cout << endl;
}

// 顺序排序
void Sort02()
{
	using namespace std;
	int numbers[]{ 2, 3, 6, 1, 29, 32, 12, 33 };
	int numbers_size = sizeof(numbers) / sizeof(int);
	for (int i = 0; i < numbers_size; i++)
	{
		int min_index = i;
		for (int j = i; j < numbers_size; j++)
		{
			if (numbers[j] < numbers[min_index]) {
				min_index = j;
			}
		}
		int temp_num = numbers[i];
		numbers[i] = numbers[min_index];
		numbers[min_index] = temp_num;
	}
	for (int n : numbers) cout << n << ",";
	cout << endl;
}

// 插值排序
void Sort03()
{
	using namespace std;
	int numbers[]{ 2, 3, 6, 1, 29, 32, 12, 33 };
	int numbers_size = sizeof(numbers) / sizeof(int);

	for (int i = 0; i < numbers_size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (numbers[i] < numbers[j])
			{
				int temp_number = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp_number;
			}
		}
	}
	for (int n : numbers) cout << n << ",";
	cout << endl;
}

// 1. 计算100内的素数(只能被1和自身整除的数)
void Test01()
{
	using namespace std;
	for (int i = 1;  i <= 100;  i++)
	{
		bool valid = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				valid = false;
				break;
			}
		}
		if (valid) cout << i << ",";
	}
	cout << endl;
}

// 2. 在一个数组中随意输入4个数，并将4个数从大到小排序
void Test02()
{
	using namespace std;
	const int numbers_size = 4;
	int numbers[numbers_size]{};
	int input_num = 0;
	int index = 0;
FLAG:
	cout << "输入第" << index + 1 << "个数";
	cin >> input_num;
	numbers[index] = input_num;
	index++;
	if (index < numbers_size) goto FLAG;

	// 从大到小排序 使用顺序排序
	for (int i = 0; i < numbers_size; i++)
	{
		int max_index = i;
		for (int j = i; j < numbers_size; j++)
		{
			if (numbers[j] > numbers[max_index])
			{
				max_index = j;
			}
		}
		int temp_num = numbers[i];
		numbers[i] = numbers[max_index];
		numbers[max_index] = temp_num;
	}
	for (int num : numbers) cout << num << ",";
	cout << endl;
}

// 3. 将数组[4, 65, 75, 77, 8, 44, 55, 33, 54]进行调转。并输出。
void Test03()
{
	using namespace std;
	int numbers[] = { 4, 65, 75, 77, 8, 44, 55, 33, 54 };
	int number_size = sizeof(numbers) / sizeof(int);

	for (int i = 0; i <= number_size / 2; i++)
	{
		int temp_num = numbers[i];
		numbers[i] = numbers[number_size - i - 1];
		numbers[number_size - i - 1] = temp_num;
	}
	for (int num : numbers) cout << num << ",";
	cout << endl;
}

// 4. 一张纸的厚度是0.0001米，将纸对折，对折多少次后，厚度将是8848米
void Test04()
{
	using namespace std;

	float h = 0.0001f;
	int number = 0;

	while (h < 8848)
	{
		h *= 2;
		number += 1;
	}
	cout << number << "次后高度达到8848米" << endl;
}

// 5. 定义一个整型变量sum，然后分别把1~100之间的数字依次累加到sum中，
//    当sum的值大于500的时候，中断操作，输出次数
void Test05()
{
	using namespace std;
	int sum = 0;
	int i = 0;
	for (; i <= 100; i++)
	{
		sum += i;
		if (sum > 500) break;
	}
	cout << i << "次" << endl;
}

// 6. do..while 验证用户输入 用户名 admin 密码 888888
void Test06()
{
	using namespace std;
	string username = "";
	string password = "";

	do
	{
		cout << "请输入用户名：";
		cin >> username;
		cout << "请输入密码：";
		cin >> password;
	} while (username != "admin" || password != "888888");
}

// 7. 一个球从100米落下，每次落地反跳原来高度一半，求第十次落地时共经历了多少米，第十次反弹多高
void Test07()
{
	using namespace std;
	float start_h = 100.0f;
	float sum_h = 0;

	for (int i = 0; i < 10; i++)
	{
		sum_h += (i == 0 ? start_h : start_h * 2);
		start_h /= 2;
	}
	cout << "共经历" << sum_h << "米" << endl;
	cout << "第十次反弹" << start_h << endl;
}

// 8. 接上题，球经历多少次反弹后，反弹高度小于1米
void Test08()
{
	using namespace std;
	float start_h = 100.0f;
	int num = 0;

	while (start_h >= 1)
	{
		start_h /= 2;
		num++;
	}
	cout << "共经历" << num << "次，反弹高度小于1米" << endl;
}

// 9. 用while、continue实现计算1~100之间的除了能被7整除之外所有整数和
void Test09()
{
	using namespace std;
	int sum = 0;
	int i = 1;
	while (i <= 100)
	{
		if (i % 7 == 0)
		{
			i++;
			continue;
		}
		else
		{
			sum += i;
			i++;
		}
	}
	cout << sum << endl;
}

int main()
{
	//WhileLoop();
	Sort01(); // 冒泡排序
	Sort02(); // 顺序排序
	Sort03(); // 插值排序
	//Test01();
	//Test02();
	//Test03();
	//Test04();
	//Test05();
	//Test06();
	//Test07();
	//Test08();
	//Test09();
	system("pause");
}