#include <iostream>
#include <string>

using namespace std;
// ��̬��Ա����
class Person
{
public:
	int number;
	static string name;

	string GetName()
	{
		return name;
	}

	// ��̬��Աֻ�ܷ��ʾ�̬��Ա
	/*static int GetNumber()
	{
		return number;
	}*/
};
// ��̬���Ա������������������ʼ�����൱���������name������
string Person::name = "NULL";

// �̳к��ʵ��Ҳ�Ṳ����ľ�̬��Ա����
class User : public Person
{
public:
	static string name;
};
string User::name = "NULL";

// ����ģʽ
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
	SingletonClass(SingletonClass&) {}; // ˽�л��������죬����ʹ�ÿ�������ʱ�����µ�ʵ��
	static SingletonClass* instance;
};
SingletonClass* SingletonClass::instance = nullptr;


// ����1. vector
#include <vector>
void Vector()
{
	using namespace std;
	vector<int>* _numbers = new vector<int>;

	vector<int> numbers = { 1, 2, 3, 4, 5 };
	// ���Ԫ��
	numbers.push_back(0); // push_back������ĩβ���Ԫ��
	numbers.insert(numbers.begin() + 1, (10, 2)); // insert ��ָ��

	// vector�����±��ȡֵ
	cout << numbers[numbers.size() - 1] << endl;
	cout << numbers.at(numbers.size() - 1) << endl;

	// ʹ�õ�����ȡ��ȫ��Ԫ��
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;

	// ɾ��Ԫ��
	numbers.erase(numbers.begin()); // ɾ������Ԫ��
	numbers.erase(numbers.begin(), numbers.end()); // ɾ����ΧԪ�� [begin, end) ����ҿ�
	numbers.clear(); // �������

	// �п�
	numbers.size() == 0; // ʹ��size�ж�
	numbers.begin() == numbers.end(); // ʹ��iterator�ж�
	numbers.empty(); // ʹ���пպ���
}

int main()
{
	//Person p1;
	//Person p2;
	//p1.name = "С��";
	//p2.name = "С��";

	//cout << p1.name << endl;
	//cout << Person::name << endl;

	//User u1;
	//cout << u1.name << endl;

	//u1.name = "СU";
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