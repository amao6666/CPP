#include <iostream> //# 预处理符 include 导入文件 iostram -> in out stream 输入输出流
#include <string> //导入string文件
#include <map>
//using namespace std; // 使用命名空间 std 可以单独使用：std::cout, 也可以统一使用

/*
函数：返回值类型 函数名(参数列表)
int function(*args)
{
	函数体
	return int
 }
*/


void InitConsoleWindow() 
{
	system("title 我是黑窗口"); // 调用系统指令，修改黑窗口Title
	system("mode con cols=100 lines=20"); // 设置console window size
	system("color 0A"); // 调用系统指令，修改窗口颜色。0代表前景色，1代表背景色，A使用16进制表示颜色
}

void PrintHelloWorld()
{
	// 单独使用std命名空房
	std::cout << "Holle World!" << std::endl; //c out输出字符到屏幕，end l输出换行符
}

void InputValue()
{
	using namespace std;
	int number; // int 声明变量 number;
	cout << "请输入：" << endl;
	cin >> number; // c in处理输入 
	cout << "刚刚输入的数：" << number << endl;
}

void AddUser()
{
	using namespace std;
	
	string name = "";
	int age = 0;

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入年龄：" << endl;
	cin >> age;

	if (name == "小黑")
	{
		cout << "是小黑呀！" << endl;
	}
	else if (name == "小红")
	{
		cout << "是小红呀！" << endl;
	}
	else
	{
		cout << "你是谁呀！" << endl;
	}
}

void SelectUser()
{

}

/*
登录注册小功能
*/

// 全局变量存储用户信息
std::string name = "";
int ID = 0;
std::string password = "";

void Quit()
{
	std::cout << "再见！" << std::endl;
	//exit(1);
}

void LoginSuccess()
{
	using namespace std;
	cout << "登录成功！" << endl;
	cout << "用户名：" << name << "         " << "用户编号：" << ID << endl;
	Quit();
}

void Login()
{
	using namespace std;
	int r_ID = 0;
	string r_password = "";
	string relogin = "";
	
	cout << "登录" << endl;

	// 输入用户编号
	cout << "用户编号：";
	cin >> r_ID;
	// 输入密码
	cout << "密码：";
	cin >> r_password;
	
	if (ID == r_ID && password == r_password)
	{
		LoginSuccess();
	}
	else
	{
		cout << "登录失败，是否重新登录？(Y/n)";
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
	cout << "是否进行登录：(Y/n)";
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

	// 输入用户名
	cout << "用户名：";
	cin >> r_name;
	// 输入用户编号
	cout << "用户编号：";
	cin >> r_ID;
	// 输入密码
	cout << "密码：";
	cin >> r_password;
	// TODO: 密码强度验证
	cout << "注册成功！" << endl;
	
	// 存储用户信息
	name = r_name;
	ID = r_ID;
	password = r_password;

	StartLogin();
}

void Start()
{
	using namespace std;
	int res = 0;
	cout << "请选择操作(1. 登录 2. 注册): ";
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
	// 调用系统指令关机
	system("shutdown -P"); // 直接关机
	system("shutdown -I"); // 注销计算机
	system("shutdown -s -t 60"); // 延迟关机
}

// main函数程序入口
int main() {
	using namespace std; // 在函数里使用统一命名空间
	InitConsoleWindow();
	//PrintHelloWorld();
	//system("cls"); //调用系统指令清屏
	//system("pause"); // 调用系统指令，在调试时暂停代码执行，可以做简单的调试
	//InputValue();
	//AddUser();
	Start();
	system("pause");
	// ShutDown();
}