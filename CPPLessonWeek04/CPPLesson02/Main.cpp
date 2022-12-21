#include <iostream>
#include <vector>
#include <algorithm> // 算法
using namespace std;

bool SortInt(int a, int b)
{
	return a < b;
}

// Lambda传参
void LambdaArgs(void (*lambda) (int, int))
{
	(*lambda)(2, 3);
}

// 匿名函数 Lambda
void Lambda()
{
	// 捕获列表捕获的是匿名函数定义时所在的作用域内的所有局部变量
	// 语法 [捕获列表](参数列表)->返回类型{函数体}
	[](int a)-> int {return 0; };

	int age = 10;
	string name;
	// 无捕获lambda
	[] {};
	// 值捕获lambda，不能对捕获到的局部变量赋值
	[=] {};
	// 值捕获特例
	[=, &age] {age = 10; }; //引用捕获才能对局部变量赋值
	// 引用捕获lambda
	[&] {};
	// 引用捕获特例
	//[&, age] {age = 10; }; // 引用捕获，只值捕获age

	// 使用实参执行Lambda
	LambdaArgs(
		[](int a, int b) {
			cout << a + b << endl;
		}
	);

	// 使用变量执行lambda
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

// Pair和Map
void Pair()
{
	pair<int, string> p1{ 1, "小黑" };
	pair<int, string> p2{ 2, "小红" };
	pair<int, string> p3 = make_pair(3, "小白");

	// 访问对
	p1.first;
	p1.second;
}

#include <map>
void Map()
{
	map<int, string> _map;
	_map.insert(make_pair(3, "小黑"));
	_map.insert(pair<int, string>{1, "小红"});
	_map.insert(map<int, string>::value_type(0, "小白"));
	_map[10] = "小黄";

	// !!!!!! c++的map在插入键值对时会经按照key的正序排序！！！！！！
	// map实际插入值的时候会按照key的顺序维护一个红黑树，所以map取值的时间复杂度为O(log n)

	// hash_map 或 unorderd_map是无序的，所以根据key取值的时间复杂度为O(1)
	// hash_map是经典的哈希算法实现的key -> 存储地址的映射, 哈希冲突是影响取值时间复杂度的关键，如果发生哈希冲突会增加key后面单向链表的长度

	// map遍历
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

	//// sort排序算法
	//sort(v_vector.begin(), v_vector.end());
	//// 使用lambda表达式倒序排序
	//sort(v_vector.begin(), v_vector.end(), [](int a, int b){ return a > b; });

	//for (vector<int>::iterator it = v_vector.begin(); it != v_vector.end(); it++)
	//{
	//	cout << *it << ",";
	//}
	//cout << endl;
	//// 函数指针排序
	//bool (*SortIntPtr) (int, int) = SortInt;
	//sort(v_vector.begin(), v_vector.end(), SortIntPtr);

	//// for_each算法
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