#include <iostream> //# Ԥ����� include �����ļ� iostram -> in out stream ���������
#include <string> //����string�ļ�
#include <map>
//using namespace std; // ʹ�������ռ� std ���Ե���ʹ�ã�std::cout, Ҳ����ͳһʹ��

/*
����������ֵ���� ������(�����б�)
int function(*args)
{
	������
	return int
 }
*/


void InitConsoleWindow() 
{
	system("title ���Ǻڴ���"); // ����ϵͳָ��޸ĺڴ���Title
	system("mode con cols=100 lines=20"); // ����console window size
	system("color 0A"); // ����ϵͳָ��޸Ĵ�����ɫ��0����ǰ��ɫ��1������ɫ��Aʹ��16���Ʊ�ʾ��ɫ
}

void PrintHelloWorld()
{
	// ����ʹ��std�����շ�
	std::cout << "Holle World!" << std::endl; //c out����ַ�����Ļ��end l������з�
}

void InputValue()
{
	using namespace std;
	int number; // int �������� number;
	cout << "�����룺" << endl;
	cin >> number; // c in�������� 
	cout << "�ո����������" << number << endl;
}

void AddUser()
{
	using namespace std;
	
	string name = "";
	int age = 0;

	cout << "������������" << endl;
	cin >> name;

	cout << "���������䣺" << endl;
	cin >> age;

	if (name == "С��")
	{
		cout << "��С��ѽ��" << endl;
	}
	else if (name == "С��")
	{
		cout << "��С��ѽ��" << endl;
	}
	else
	{
		cout << "����˭ѽ��" << endl;
	}
}

void SelectUser()
{

}

/*
��¼ע��С����
*/

// ȫ�ֱ����洢�û���Ϣ
std::string name = "";
int ID = 0;
std::string password = "";

void Quit()
{
	std::cout << "�ټ���" << std::endl;
	//exit(1);
}

void LoginSuccess()
{
	using namespace std;
	cout << "��¼�ɹ���" << endl;
	cout << "�û�����" << name << "         " << "�û���ţ�" << ID << endl;
	Quit();
}

void Login()
{
	using namespace std;
	int r_ID = 0;
	string r_password = "";
	string relogin = "";
	
	cout << "��¼" << endl;

	// �����û����
	cout << "�û���ţ�";
	cin >> r_ID;
	// ��������
	cout << "���룺";
	cin >> r_password;
	
	if (ID == r_ID && password == r_password)
	{
		LoginSuccess();
	}
	else
	{
		cout << "��¼ʧ�ܣ��Ƿ����µ�¼��(Y/n)";
		cin >> relogin;
		if (relogin == "Y") {
			Login();
		}
		else
		{
			Quit();
		}
	}
	
}

void StartLogin()
{
	using namespace std;
	string res = "";
	cout << "�Ƿ���е�¼��(Y/n)";
	cin >> res;
	if (res == "Y") {
		Login();
	}
	else
	{
		Quit();
	}
}

void Registe()
{
	using namespace std;
	string r_name = "";
	int r_ID = 0;
	string r_password = "";

	// �����û���
	cout << "�û�����";
	cin >> r_name;
	// �����û����
	cout << "�û���ţ�";
	cin >> r_ID;
	// ��������
	cout << "���룺";
	cin >> r_password;
	// TODO: ����ǿ����֤
	cout << "ע��ɹ���" << endl;
	
	// �洢�û���Ϣ
	name = r_name;
	ID = r_ID;
	password = r_password;

	StartLogin();
}

void Start()
{
	using namespace std;
	int res = 0;
	cout << "��ѡ�����(1. ��¼ 2. ע��): ";
	cin >> res;
	if (res == 2)
	{
		Registe();
	}
	else if (res == 1)
	{
		Login();
	}
}

void ShutDown()
{
	// ����ϵͳָ��ػ�
	system("shutdown -P"); // ֱ�ӹػ�
	system("shutdown -I"); // ע�������
	system("shutdown -s -t 60"); // �ӳٹػ�
}

// main�����������
int main() {
	using namespace std; // �ں�����ʹ��ͳһ�����ռ�
	InitConsoleWindow();
	//PrintHelloWorld();
	//system("cls"); //����ϵͳָ������
	//system("pause"); // ����ϵͳָ��ڵ���ʱ��ͣ����ִ�У��������򵥵ĵ���
	//InputValue();
	//AddUser();
	Start();
	system("pause");
	// ShutDown();
}