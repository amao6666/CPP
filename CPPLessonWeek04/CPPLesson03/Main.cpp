#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <vector>

using namespace std;

// 运算符重载
struct Person
{
	int age;
	string name;
};

Person operator+(Person& p1, Person& p2)
{
	Person temp_person;
	temp_person.age = p1.age + p2.age;
	return temp_person;
}

void operator+=(Person& p1, Person& p2)
{
	Person temp_person;
	temp_person.age = p1.age + p2.age;
	p1 = temp_person;
}

// 仿函数
class MyClass
{
public:
	void operator() (string name)
	{
		cout << typeid(this).name() << endl;
		cout << name << endl;
	}

	MyClass()
	{
		cout << "发生了实例化" << endl;
	}
};

// 相当于全局都可调用的函数
class SortMap
{
public:
	bool operator() (int a, int b) const //必须是常量函数，不能修改成员属性
	{
		return a > b;
	}
};

void MapSortDesc()
{
	map<int, string, SortMap> mp; // 带有自定义排序方式的map
	mp.insert(make_pair(10, "a"));
	mp.insert(make_pair(20, "b"));
	
	// 不会覆盖原来的值
	mp.insert(make_pair(1, "c"));
	mp.insert(make_pair(1, "d"));

	// 会覆盖原来的值
	mp[1] = "v";

	for_each(mp.begin(), mp.end(), [](pair<int, string> p) {cout << p.first << "," << p.second << endl; });
}

// multimap 所属头文件 map
// 允许key冲突，猜测相同的key的值是放在链表里
void Multimap()
{
	cout << "==========================Multimap=========================" << endl;
	multimap<int, string> m_map;
	m_map.insert(make_pair(10, "a"));
	m_map.insert(make_pair(11, "a"));
	m_map.insert(make_pair(10, "a"));

	/*auto item = m_map.find(10);
	cout << item->first << endl;
	cout << item->second << endl;*/

	// 遍历
	for_each(m_map.begin(), m_map.end(), [](pair<int, string> p) {cout << p.first << "," << p.second << endl; });

	// 查找
	// 1. 使用find和count
	cout << "========================find and count=================" << endl;
	auto count = m_map.count(10);
	auto item = m_map.find(10);

	while (count--)
	{
		cout << item->second << endl;
		item++;
	}
	// 2. 使用lower_bound和upper_bound
	cout << "========================lower_bound and upper_bound=================" << endl;
	for (auto it = m_map.lower_bound(10); it != m_map.upper_bound(10); it++)
	{
		cout << it->second << endl;
	}
	// 3. 使用equal_range
	cout << "========================euqal_range=================" << endl;
	for (auto pop = m_map.equal_range(10); pop.first != pop.second; pop.first++)
	{
		cout << pop.first->second << endl;
	}
}

class CoordCompare
{
public:
	bool operator()(COORD c1, COORD c2) const
	{
		if (c1.X != c2.X) return c1.X < c2.X;
		return c1.Y < c2.Y;
	}
};

typedef pair<COORD, string> COORD_PAIR;
bool operator==(COORD c1, COORD c2)
{
	return c1.X == c2.X && c1.Y == c2.Y;
}
// COORD Map
void CoordMap()
{
	map < COORD, string, CoordCompare > mp{
		{ { 0, 0 }, "a"},
		{ { 1, 1 }, "a"},
		{ { 2, 2 }, "b"}
	};
	//mp[{0, 0}] = "a";
	mp.insert(COORD_PAIR{ { 0, 0 }, "a"});
	mp.insert(COORD_PAIR{ { 1, 1 }, "a"});
	mp.insert(COORD_PAIR{ { 1, 0 }, "a"});
	mp.insert(COORD_PAIR{ { 0, 0 }, "b"});

	cout << "================================================" << endl;
	cout << mp.count({ 2, 0 }) << endl;
	cout << (mp.find({ 2, 0 }) != mp.end()) << endl;
	cout << "================================================" << endl;

	for_each(mp.begin(), mp.end(), [](COORD_PAIR p) {cout << "{" << p.first.X << "," << p.first.Y << "}" << "," << p.second << endl; });
}

struct SpriteBodyItem
{
	COORD position;
	std::string fill;

	bool operator<(SpriteBodyItem s2) const
	{
		if (position.X != s2.position.X) return position.X < s2.position.X;
		return position.Y < s2.position.Y;
	}

	bool operator==(SpriteBodyItem s2) const
	{
		return true;
	}
};
// COORD Set
void CoordSet()
{
	set<SpriteBodyItem> _set{
		{ {0, 0}, " " },
		{ {1, 0}, "*" },
		{ {2, 0}, " " },
		{ {0, 1}, "*" },
		{ {1, 1}, "*" },
		{ {2, 1}, "*" }
	};

	cout << _set.count({ {1, 0}, " " }) << endl;
	cout << (_set.find({ {0, 0}, " " }) == _set.end()) << endl;
	
	for (auto item : _set)
	{
		cout << "{" << item.position.X << "," << item.position.Y << "}" << "," << item.fill << endl;
	}

	cout << "===================================指针set======================================" << endl;

	SpriteBodyItem* ptr1 = new SpriteBodyItem{ {0, 0}, " " };
	SpriteBodyItem* ptr2 = new SpriteBodyItem{ {1, 0}, "*" };
	SpriteBodyItem* ptr3 = new SpriteBodyItem{ {2, 0}, " " };
	SpriteBodyItem* ptr4 = new SpriteBodyItem{ {0, 1}, "*" };
	SpriteBodyItem* ptr5 = new SpriteBodyItem{ {1, 1}, "*" };
	SpriteBodyItem* ptr6 = new SpriteBodyItem{ {2, 1}, "*" };

	set<SpriteBodyItem*> _set_ptr {
		ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
	};

	int i = 0;
	for (set<SpriteBodyItem*>::iterator it = _set_ptr.begin(); it != _set_ptr.end(); it++)
	{
		if (i == 1)
		{
			auto t_it = it++;
			_set_ptr.erase(t_it);
			//it++;
		}
		i++;
	}

	cout << "===================================================================================" << endl;

	for (auto item : _set_ptr)
	{
		cout << "{" << (*item).position.X << "," << (*item).position.Y << "}" << "," << (*item).fill << endl;
		//_set_ptr.erase(_set_ptr.find(item));
	}

	SpriteBodyItem* ptr7 = new SpriteBodyItem{ {2, 1}, "*" };
	cout << _set_ptr.count(ptr1) << endl;
	cout << _set_ptr.count(ptr7) << endl;
}

// set 可以理解为有序且没有重复元素的集合

#include <set>
void TestSet()
{
	set<int> st;
	st.insert(3);
	st.insert(2);
	st.insert(4);

	st.insert(4); // 会覆盖

	/*set<int>* int_set = new set<int>;*/

	for_each(st.begin(), st.end(), [](int item) {cout << item << endl; });
}

int main()
{
	//Person p1 = { 10, "小黑" };
	//Person p2 = { 12, "小白" };

	//Person p3 = p1 + p2;
	//p1 += p2;

	//// 仿函数
	//MyClass mc;
	//mc("123");

	//MyClass() ("1234");

	//MapSortDesc();
	Multimap();

	//TestSet();

	CoordMap();
	CoordSet();
	system("pause");
}