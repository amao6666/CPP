#include <iostream>
#include <string>

using namespace std;
//�������죬������ʵ����ֵʱ
class Person
{
public:
	string name;
	int* ptr;
	Person()
	{
		name = "amao";
		ptr = new int(10);
		cout << "����Ĭ�Ϲ���" << endl;
	}

	Person(Person &person)
	{
		name = person.name;
		ptr = new int(*person.ptr); // ��Ҫ���
		cout << "���ǿ�������" << endl;
	}

	~Person()
	{
		// ����������ʵ��������ʱ���ã������Ա�����
		// ��Ҫ�ֶ��ͷſռ䣬����ָ��
		delete ptr;
		ptr = nullptr;
		cout << "������������" << endl;
	}
};

void CopyFunc(Person& p)
{
	Person p1; // ���ں�������ʱ�����գ���ʱ����������������
	cout << "������Ҳ������" << endl;
	cout << p.name << endl;
}

// ��ļ̳�
class Animal
{
public:
	string name;
	void sleep()
	{
		cout << "˯��" << endl;
	}

	virtual void eat(string food)
	{
		cout << "�Է���" << food << endl;
	}

	// ���麯��
	//virtual void move() = 0;//���麯�������ڶ�����ӿڣ��𵽹淶���������
	// ���������д���麯�����������û����д���麯��Ҳ���ɳ����࣬�����಻�ܱ�ʵ����

	Animal()
	{
		cout << "����Animal�޲ι���" << endl;
	}

protected:
	int sex;
private:
	int age;
};

// public��������η���������������������ķ���Ȩ�� Ĭ����private
class Dog : public Animal
{
public:
	//�ض���sleep����
	int sleep(int time)
	{
		Animal::sleep();//���ø����sleep����
		return time;
	}

	// ʹ��override�����ĺ���ֻ���ض��庯���߼���������д������������
	virtual void eat(string food) override
	{
		//return 123;
	}

	void GetAge()
	{
		sex;
	}
};

// ��̳У�һ������̳��ڶ������

// �²� ��̳�ʱ���ܰ��ո���̳�˳����ø��๹�캯��
// ��̳е����⣬���������������ͬ�����ԣ��������������ʱ�ᱨ����ȷ���쳣
// ����ͨ����������·���ķ�ʽ���

// ���μ̳У���̳еĶ��������ͬһ������
// ���⣺������ʹ��virtual�ؼ�������������̳н����
// 1. ����ȷ
// 2. �ڴ�ռ��


// ��̬
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
	
	//Dog dog; //����ø����޲ι��죬ʹ��ί�й��췽ʽ
	//dog.name;
	
	//Animal animal1;
	//animal1.sleep();
	//animal1.eat("111");

	//Animal dog1;
	//dog1.sleep(); // ����ݶ��������Ϊ������Ѱ��Ŀ�꺯��
	//dog1.eat("222"); // �����ֶ�̬����Ȼ��Animal���͵���������������ر���Ϊ

	Gone gone;
	gone.Test1();
	gone.Test2(2);

	Weapon* weapon1 = &gone;
	weapon1->Test1(); // Test1()�����麯�������Ե���Weapon������ĺ���
	weapon1->Test2(); // Test2()���麯�������Ե���ʵ����������麯��

	// �麯��ԭ��
	// 1. �������麯��ʱ���ڴ���ʵ��ʱ�ὫV-table���麯�����浽�����
	// 2. �̳�ʱ���������Ὣ������麯�������ǰ�棬��������ض��常����麯������ʹ��������麯���滻V-table�ĺ���ָ�롣
	// 3. ����ʱ�ȸ���ʵ����v-ptr�ҵ�v-table�Ӷ��ҵ����õ��麯��ָ�룬Ȼ����е��á�

	Weapon* weapon = new Gone;
	weapon->Test1();
	weapon->Test2();

	system("pause");
}