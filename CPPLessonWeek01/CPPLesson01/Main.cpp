#include <iostream> //# 预处理符 include 导入文件 iostram -> in out stream 输入输出流
//using namespace std; // 使用命名空间 std 可以单独使用：std::cout, 也可以统一使用

// main函数程序入口
int main() {
	using namespace std; // 在函数里使用统一命名空间
	system("title 我是黑窗口"); // 调用系统指令，修改黑窗口Title
	system("color 0A"); // 调用系统指令，修改窗口颜色。0代表前景色，1代表背景色，A使用16进制表示颜色

	cout << "Holle World!" << endl; //c out输出字符到屏幕，end l输出换行符

	// 单独使用std命名空房
	// std::cout << "Hello World!" << std::endl;
	system("cls"); //调用系统指令清屏
	system("pause"); // 调用系统指令，在调试时暂停代码执行，可以做简单的调试
	
	int number; // int 声明变量 number;
	cout << "请输入：" << endl;
	cin >> number; // c in处理输入 
	cout << "刚刚输入的数：" << number << endl;
	system("pause");
}