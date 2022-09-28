#include <iostream>

// 不加限定符的枚举声明
// 枚举命名需要在前面加E
// 枚举的项为右值
enum EGameState
{
	Wait,
	Runing,
	End
};

// 加限定符的枚举定义
enum class ECharacterState
{
	Wait,
	Dead,
	Life
};

void Enum()
{
	using namespace std;
	EGameState game_state;
	game_state = Wait; // 此时给枚举赋值时并不知到Wait属于哪个枚举

	// 加限定符的枚举类型初始化方式
	ECharacterState character_state;
	character_state = ECharacterState::Wait; //限定符的作用，增加代码可读

	cout << "sizeof(EGameState) = " << sizeof(EGameState) << endl;// 4字节？
	cout << "sizeof(Wait) = " << sizeof(Wait) << endl;
	cout << "Wait = " << Wait << endl;//打印出的是数值0

	EGameState* wait = &game_state;
	cout << "*(wait + 1) = " << *(wait + 1) << endl;
}

// 穷举法案例
// 5个颜色的球，每次取三个，记录所有没有重复颜色的组合

enum EColor
{
	red, yellow, blue, green, black
};

void Test()
{
	using namespace std;
	for (int i = red; i <= black; i++)
	{
		for (int j = red; j <= black; j++)
		{
			if (i != j)
			{
				for (int k = red; k <= black; k++)
				{
					if (k != i && k != j)
					{
						cout << "一个成功的组合" << endl;
					}
				}
			}
		}
	}
}

class Person
{
	// 友元函数：为函数赋予私有成员访问权限
	friend void Test();
	//friend void Person::getName(); // 为类的成员函数赋予私有成员访问权限
	friend class Person; // 为类赋予私有成员访问权限
	int iii;
public:
	std::string name;
	std::string getName();

	// 构造函数是静态成员
	/*Person()
	{

	}*/

	Person(std::string _name, int _age)
	{
		name = _name;
		age = _age;
	}

	// this 指针初始化
	/*Person(std::string _name, int _age)
	{
		this->name = _name;
		this->age = _age;
	}*/

	// 列表初始化，无法初始化继承到的成员属性
	/*Person(std::string _name, int _age):name(_name),age(_age)
	{}*/

	// 委托构造,先执行委托，再执行构造
	/*Person(std::string _name, int _age):Person()
	{

	}*/
private:
	int age;
	//int getAge();
	//void setAge(int);

	// 构造函数也受访问标识符约束
	//Person(std::string _name, int _age)
	//{
	//	name = _name;
	//	age = _age;
	//}
};

std::string Person::getName()
{
	return name;
}

/*int Person::getAge()
{
	return age;
}

void Person::setAge(int _age)
{
	age = _age;
}*/

int main()
{
	using namespace std;
	//Enum();
	Person p = Person("amao", 12);
	cout << p.name << endl;
	cout << p.getName() << endl;
	p.name = "amao123";
	cout << p.getName() << endl;
	//cout << p.getAge() << endl;
	
	system("pause");
}