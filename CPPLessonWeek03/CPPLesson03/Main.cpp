#include <iostream>
#include <string>

using namespace std;
//拷贝构造，发生在实例赋值时
class Person
{
public:
	string name;
	int* ptr;
	Person()
	{
		name = "amao";
		ptr = new int(10);
		cout << "我是默认构造" << endl;
	}

	Person(Person &person)
	{
		name = person.name;
		ptr = new int(*person.ptr); // 需要深拷贝
		cout << "我是拷贝构造" << endl;
	}

	~Person()
	{
		// 析构函数，实例被销毁时调用，不可以被重载
		// 需要手动释放空间，回收指针
		delete ptr;
		ptr = nullptr;
		cout << "我是析构函数" << endl;
	}
};

void CopyFunc(Person& p)
{
	Person p1; // 会在函数结束时被回收，此时会调用类的析构函数
	cout << "不拷贝也不构造" << endl;
	cout << p.name << endl;
}

// 类的继承
class Animal
{
public:
	string name;
	void sleep()
	{
		cout << "睡觉" << endl;
	}

	virtual void eat(string food)
	{
		cout << "吃饭：" << food << endl;
	}

	// 纯虚函数
	//virtual void move() = 0;//纯虚函数，用于定义类接口，起到规范子类的作用
	// 子类必须重写纯虚函数，子类如果没有重写纯虚函数也会变成抽象类，抽象类不能被实例化

	Animal()
	{
		cout << "我是Animal无参构造" << endl;
	}

protected:
	int sex;
private:
	int age;
};

// public类访问修饰符，用于升级父类在子类的访问权限 默认是private
class Dog : public Animal
{
public:
	//重定义sleep函数
	int sleep(int time)
	{
		Animal::sleep();//调用父类的sleep函数
		return time;
	}

	// 使用override声明的函数只能重定义函数逻辑，不能重写（声明）函数
	virtual void eat(string food) override
	{
		//return 123;
	}

	void GetAge()
	{
		sex;
	}
};

// 多继承，一个子类继承于多个父类

// 猜测 多继承时可能按照父类继承顺序调用父类构造函数
// 多继承的问题，如果两个父类里有同名属性，在子类调用属性时会报不明确的异常
// 可以通过标明属性路径的方式解决

// 菱形继承，多继承的多个父类有同一个父类
// 问题：（可以使用virtual关键字声明父类虚继承解决）
// 1. 不明确
// 2. 内存占用


// 多态
class Weapon
{
public:
	int damage;
	void Test1()
	{
		cout << damage << endl;
		cout << typeid(this).name() << endl;
	}

	virtual void Test2()
	{
		cout << typeid(this).name() << endl;
	}
};

class Gone : public Weapon
{
public:
	Gone()
	{
		damage = 100;
	}
	/*void Test1()
	{
		cout << "Gone  " << typeid(this).name() << endl;
	}*/

	virtual void Test2(int a)
	{
		cout << "Gone  " << typeid(this).name() << endl;
	}
};


int main()
{
	/*Person p1;
	Person p2 = p1;
	CopyFunc(p2);*/
	
	//Dog dog; //或调用父类无参构造，使用委托构造方式
	//dog.name;
	
	//Animal animal1;
	//animal1.sleep();
	//animal1.eat("111");

	//Animal dog1;
	//dog1.sleep(); // 会根据对象的类型为接收者寻找目标函数
	//dog1.eat("222"); // 会体现多态，虽然是Animal类型但是体现了子类的特别行为

	Gone gone;
	gone.Test1();
	gone.Test2(2);

	Weapon* weapon1 = &gone;
	weapon1->Test1(); // Test1()不是虚函数，所以调用Weapon类型里的函数
	weapon1->Test2(); // Test2()是虚函数，所以调用实例对象里的虚函数

	// 虚函数原理：
	// 1. 类里有虚函数时，在创建实例时会将V-table（虚函数表）存到对象里。
	// 2. 继承时，子类对象会将父类的虚函数表放在前面，如果子类重定义父类的虚函数，会使用子类的虚函数替换V-table的函数指针。
	// 3. 调用时先根据实例的v-ptr找到v-table从而找到调用的虚函数指针，然后进行调用。

	Weapon* weapon = new Gone;
	weapon->Test1();
	weapon->Test2();

	system("pause");
}