#include <iostream>
#include <vector>
#include <algorithm> // �㷨
using namespace std;

bool SortInt(int a, int b)
{
	return a < b;
}

// Lambda����
void LambdaArgs(void (*lambda) (int, int))
{
	(*lambda)(2, 3);
}

// �������� Lambda
void Lambda()
{
	// �����б������������������ʱ���ڵ��������ڵ����оֲ�����
	// �﷨ [�����б�](�����б�)->��������{������}
	[](int a)-> int {return 0; };

	int age = 10;
	string name;
	// �޲���lambda
	[] {};
	// ֵ����lambda�����ܶԲ��񵽵ľֲ�������ֵ
	[=] {};
	// ֵ��������
	[=, &age] {age = 10; }; //���ò�����ܶԾֲ�������ֵ
	// ���ò���lambda
	[&] {};
	// ���ò�������
	//[&, age] {age = 10; }; // ���ò���ֵֻ����age

	// ʹ��ʵ��ִ��Lambda
	LambdaArgs(
		[](int a, int b) {
			cout << a + b << endl;
		}
	);

	// ʹ�ñ���ִ��lambda
	auto _lambda = [=](int a, int b) -> int {
		return (a + b + age);
	};

	int result = _lambda(1, 2);
	cout << result << endl;
}

// Nested vector
void NestedVector()
{
	using namespace std;
	vector<vector<int>> n_vector;
	vector<int> i_vector;
	i_vector.push_back(1);
	i_vector.push_back(2);
	i_vector.push_back(3);
	i_vector.push_back(4);
	i_vector.push_back(5);

	n_vector.push_back(i_vector);
	n_vector.push_back(i_vector);
	n_vector.push_back(i_vector);
	n_vector.push_back(i_vector);
	n_vector.push_back(i_vector);

	for_each(n_vector.begin(), n_vector.end(), [](vector<int> item)
		{
			for_each(item.begin(), item.end(), [](int i)
				{
					cout << i << ",";
				}
			);
			cout << endl;
		}
	);
}

// Pair��Map
void Pair()
{
	pair<int, string> p1{ 1, "С��" };
	pair<int, string> p2{ 2, "С��" };
	pair<int, string> p3 = make_pair(3, "С��");

	// ���ʶ�
	p1.first;
	p1.second;
}

#include <map>
void Map()
{
	map<int, string> _map;
	_map.insert(make_pair(3, "С��"));
	_map.insert(pair<int, string>{1, "С��"});
	_map.insert(map<int, string>::value_type(0, "С��"));
	_map[10] = "С��";

	// !!!!!! c++��map�ڲ����ֵ��ʱ�ᾭ����key���������򣡣���������
	// mapʵ�ʲ���ֵ��ʱ��ᰴ��key��˳��ά��һ�������������mapȡֵ��ʱ�临�Ӷ�ΪO(log n)

	// hash_map �� unorderd_map������ģ����Ը���keyȡֵ��ʱ�临�Ӷ�ΪO(1)
	// hash_map�Ǿ���Ĺ�ϣ�㷨ʵ�ֵ�key -> �洢��ַ��ӳ��, ��ϣ��ͻ��Ӱ��ȡֵʱ�临�ӶȵĹؼ������������ϣ��ͻ������key���浥������ĳ���

	// map����
	for (map<int, string>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		cout << "key: " << it->first << "\t" << "value: " << it->second << endl;
	}
}

int main()
{
	//vector<int> v_vector;
	//v_vector.push_back(2);
	//v_vector.push_back(1);
	//v_vector.push_back(0);
	//v_vector.push_back(5);
	//v_vector.push_back(4);

	//// sort�����㷨
	//sort(v_vector.begin(), v_vector.end());
	//// ʹ��lambda���ʽ��������
	//sort(v_vector.begin(), v_vector.end(), [](int a, int b){ return a > b; });

	//for (vector<int>::iterator it = v_vector.begin(); it != v_vector.end(); it++)
	//{
	//	cout << *it << ",";
	//}
	//cout << endl;
	//// ����ָ������
	//bool (*SortIntPtr) (int, int) = SortInt;
	//sort(v_vector.begin(), v_vector.end(), SortIntPtr);

	//// for_each�㷨
	//for_each(v_vector.begin(), v_vector.end(), [](int a) 
	//	{
	//		if (a == 4) return false;// not stop for each
	//		cout << a << ","; 
	//	}
	//);

	//Lambda();

	//NestedVector();

	Map();
	system("pause");
}