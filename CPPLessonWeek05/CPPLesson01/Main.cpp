#include "User.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

template <typename _TyFunc>
_TyFunc Min(_TyFunc a, _TyFunc b)
{
	return a < b ? a : ((a == b) ? a : b);
}


// �ɱ������ֵ

template <typename _First>
_First ArgsTest(_First a)
{
	return a;
}
template <typename _First, typename ..._Typeargs>
_First ArgsTest(_First a, _Typeargs... args)
{
	cout << a << endl;
	cout << sizeof...(args) << endl;
	// �ݹ�������
	if (sizeof...(args) == 0) return 0;
	return a + ArgsTest(args...); // ��Ҫ������������غ�������Ϊ����ֻ�ᴫһ������first��ArgsTest
}

// ������ģ��
template <typename _Ty, size_t S>
void TestArray(_Ty (&_array)[S])
{
	for (auto item : _array)
	{
		cout << item << ",";
	}
}

int main()
{
	// ģ�庯��ָ��ģ����������
	//int min = Min<int>(10, 20);
	//cout << min << endl;

	//User<int> u; // ģ������Ҫ��ʵ����ʱָ��ģ������
	//cout << u.Add(10, 10) << endl;

	//int _array[5] { 0, 30, 10, 25, 40 };
	//u.Sort(_array, 5);

	//for_each(_array, _array + 5, [](int i) {cout << i << ","; });

	//// ģ�������ģ�庯��
	//User<int> u1;
	//u1.Min<int>(10, 20);
	int sum = ArgsTest(1, 2, 3, 4, 5);
	cout << sum << endl;

	int args[5]{ 1, 2, 3, 4, 5 };
	TestArray(args);
	system("pause");
}