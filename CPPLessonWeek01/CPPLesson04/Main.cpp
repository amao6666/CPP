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
	cout << year << "���2000���" << money << endl;
}

// ���ӹ�����ת�߼�
void Goto()
{
	using namespace std;
FLAG:
	cout << 1 << endl;
	goto FLAG;
	cout << 2 << endl;
}

// ð������
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

// ˳������
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

// ��ֵ����
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

// 1. ����100�ڵ�����(ֻ�ܱ�1��������������)
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

// 2. ��һ����������������4����������4�����Ӵ�С����
void Test02()
{
	using namespace std;
	const int numbers_size = 4;
	int numbers[numbers_size]{};
	int input_num = 0;
	int index = 0;
FLAG:
	cout << "�����" << index + 1 << "����";
	cin >> input_num;
	numbers[index] = input_num;
	index++;
	if (index < numbers_size) goto FLAG;

	// �Ӵ�С���� ʹ��˳������
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

// 3. ������[4, 65, 75, 77, 8, 44, 55, 33, 54]���е�ת���������
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

// 4. һ��ֽ�ĺ����0.0001�ף���ֽ���ۣ����۶��ٴκ󣬺�Ƚ���8848��
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
	cout << number << "�κ�߶ȴﵽ8848��" << endl;
}

// 5. ����һ�����ͱ���sum��Ȼ��ֱ��1~100֮������������ۼӵ�sum�У�
//    ��sum��ֵ����500��ʱ���жϲ������������
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
	cout << i << "��" << endl;
}

// 6. do..while ��֤�û����� �û��� admin ���� 888888
void Test06()
{
	using namespace std;
	string username = "";
	string password = "";

	do
	{
		cout << "�������û�����";
		cin >> username;
		cout << "���������룺";
		cin >> password;
	} while (username != "admin" || password != "888888");
}

// 7. һ�����100�����£�ÿ����ط���ԭ���߶�һ�룬���ʮ�����ʱ�������˶����ף���ʮ�η������
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
	cout << "������" << sum_h << "��" << endl;
	cout << "��ʮ�η���" << start_h << endl;
}

// 8. �����⣬�������ٴη����󣬷����߶�С��1��
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
	cout << "������" << num << "�Σ������߶�С��1��" << endl;
}

// 9. ��while��continueʵ�ּ���1~100֮��ĳ����ܱ�7����֮������������
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
	Sort01(); // ð������
	Sort02(); // ˳������
	Sort03(); // ��ֵ����
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