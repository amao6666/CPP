#include <iostream>
#include <string>

using namespace std;
// 静态成员属性
class Person
{
public:
	int number;
	static string name;

	string GetName()
	{
		return name;
	}

	// 静态成员只能访问静态成员
	/*static int GetNumber()
	{
		return number;
	}*/
};
// 静态属性必须类内声明，类外初始化，相当于类变量，name属于类
string Person::name = "NULL";

// 继承后的实例也会共享父类的静态成员属性
class User : public Person
{
public:
	static string name;
};
string User::name = "NULL";

// 单例模式
class SingletonClass
{
public:
	static SingletonClass* Instance()
	{
		if (!SingletonClass::instance)
		{
			SingletonClass::instance = new SingletonClass();
		}
		return SingletonClass::instance;
	}
private:
	SingletonClass() {};
	SingletonClass(SingletonClass&) {}; // 私有化拷贝构造，避免使用拷贝构造时创建新的实例
	static SingletonClass* instance;
};
SingletonClass* SingletonClass::instance = nullptr;


// 容器1. vector
#include <vector>
void Vector()
{
	using namespace std;
	vector<int>* _numbers = new vector<int>;

	vector<int> numbers = { 1, 2, 3, 4, 5 };
	// 添加元素
	numbers.push_back(0); // push_back向容器末尾添加元素
	numbers.insert(numbers.begin() + 1, (10, 2)); // insert 到指定

	// vector根据下标获取值
	cout << numbers[numbers.size() - 1] << endl;
	cout << numbers.at(numbers.size() - 1) << endl;

	// 使用迭代器取出全部元素
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;

	// 删除元素
	numbers.erase(numbers.begin()); // 删除单个元素
	numbers.erase(numbers.begin(), numbers.end()); // 删除范围元素 [begin, end) 左闭右开
	numbers.clear(); // 清空容器

	// 判空
	numbers.size() == 0; // 使用size判断
	numbers.begin() == numbers.end(); // 使用iterator判断
	numbers.empty(); // 使用判空函数
}

int main()
{
	//Person p1;
	//Person p2;
	//p1.name = "小黑";
	//p2.name = "小白";

	//cout << p1.name << endl;
	//cout << Person::name << endl;

	//User u1;
	//cout << u1.name << endl;

	//u1.name = "小U";
	//cout << p1.name << endl;

	////SingletonClass instance1; 
	//SingletonClass* instance1 = SingletonClass::Instance();
	//SingletonClass* instance2 = SingletonClass::Instance();

	//cout << (instance1 == instance2) << endl;
	//cout << instance1 << endl;
	//cout << instance2 << endl;

	Vector();
	system("pause");
}