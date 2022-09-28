#include <iostream>

// �����޶�����ö������
// ö��������Ҫ��ǰ���E
// ö�ٵ���Ϊ��ֵ
enum EGameState
{
	Wait,
	Runing,
	End
};

// ���޶�����ö�ٶ���
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
	game_state = Wait; // ��ʱ��ö�ٸ�ֵʱ����֪��Wait�����ĸ�ö��

	// ���޶�����ö�����ͳ�ʼ����ʽ
	ECharacterState character_state;
	character_state = ECharacterState::Wait; //�޶��������ã����Ӵ���ɶ�

	cout << "sizeof(EGameState) = " << sizeof(EGameState) << endl;// 4�ֽڣ�
	cout << "sizeof(Wait) = " << sizeof(Wait) << endl;
	cout << "Wait = " << Wait << endl;//��ӡ��������ֵ0

	EGameState* wait = &game_state;
	cout << "*(wait + 1) = " << *(wait + 1) << endl;
}

// ��ٷ�����
// 5����ɫ����ÿ��ȡ��������¼����û���ظ���ɫ�����

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
						cout << "һ���ɹ������" << endl;
					}
				}
			}
		}
	}
}

class Person
{
	// ��Ԫ������Ϊ��������˽�г�Ա����Ȩ��
	friend void Test();
	//friend void Person::getName(); // Ϊ��ĳ�Ա��������˽�г�Ա����Ȩ��
	friend class Person; // Ϊ�ำ��˽�г�Ա����Ȩ��
	int iii;
public:
	std::string name;
	std::string getName();

	// ���캯���Ǿ�̬��Ա
	/*Person()
	{

	}*/

	Person(std::string _name, int _age)
	{
		name = _name;
		age = _age;
	}

	// this ָ���ʼ��
	/*Person(std::string _name, int _age)
	{
		this->name = _name;
		this->age = _age;
	}*/

	// �б��ʼ�����޷���ʼ���̳е��ĳ�Ա����
	/*Person(std::string _name, int _age):name(_name),age(_age)
	{}*/

	// ί�й���,��ִ��ί�У���ִ�й���
	/*Person(std::string _name, int _age):Person()
	{

	}*/
private:
	int age;
	//int getAge();
	//void setAge(int);

	// ���캯��Ҳ�ܷ��ʱ�ʶ��Լ��
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