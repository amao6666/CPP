#pragma once
#include <algorithm>

//template <class _Ty>
// 一般使用typename关键字很少使用class关键字

template <typename _Ty>
class User
{
public:
	_Ty Add(_Ty a, _Ty b);
	void Sort(_Ty* _array, int length);

	// 模板类内的成员函数使用模板函数
	template <typename _Func>
	_Func Min(_Func a, _Func b);

	// 使用两个类型的模板,并指定一个默认类型
	//template <typename _E1, typename _E2 = int>;
};

// template class的成员函数必须放在头文件，并且不管是类内定义或类外定义，该函数一定是内联的

// 在类外定义内联函数一定要在函数定义上一行重新声明模板
template <typename _Ty>
_Ty User<_Ty>::Add(_Ty a, _Ty b)
{
	return a + b;
}

template <typename _Ty>
void User<_Ty>::Sort(_Ty* _array, int length)
{
	std::sort(_array, _array + length);
}

template <typename _Ty>
template <typename _Func>
_Func User<_Ty>::Min(_Func a, _Func b)
{
	return (a < b || a == b) ? a : b;
}

