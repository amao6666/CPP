#include <iostream> //# Ԥ����� include �����ļ� iostram -> in out stream ���������
//using namespace std; // ʹ�������ռ� std ���Ե���ʹ�ã�std::cout, Ҳ����ͳһʹ��

// main�����������
int main() {
	using namespace std; // �ں�����ʹ��ͳһ�����ռ�
	system("title ���Ǻڴ���"); // ����ϵͳָ��޸ĺڴ���Title
	system("color 0A"); // ����ϵͳָ��޸Ĵ�����ɫ��0����ǰ��ɫ��1������ɫ��Aʹ��16���Ʊ�ʾ��ɫ

	cout << "Holle World!" << endl; //c out����ַ�����Ļ��end l������з�

	// ����ʹ��std�����շ�
	// std::cout << "Hello World!" << std::endl;
	system("cls"); //����ϵͳָ������
	system("pause"); // ����ϵͳָ��ڵ���ʱ��ͣ����ִ�У��������򵥵ĵ���
	
	int number; // int �������� number;
	cout << "�����룺" << endl;
	cin >> number; // c in�������� 
	cout << "�ո����������" << number << endl;
	system("pause");
}