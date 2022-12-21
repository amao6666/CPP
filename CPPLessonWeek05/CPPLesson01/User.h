#pragma once
#include <algorithm>

//template <class _Ty>
// һ��ʹ��typename�ؼ��ֺ���ʹ��class�ؼ���

template <typename _Ty>
class User
{
public:
	_Ty Add(_Ty a, _Ty b);
	void Sort(_Ty* _array, int length);

	// ģ�����ڵĳ�Ա����ʹ��ģ�庯��
	template <typename _Func>
	_Func Min(_Func a, _Func b);

	// ʹ���������͵�ģ��,��ָ��һ��Ĭ������
	//template <typename _E1, typename _E2 = int>;
};

// template class�ĳ�Ա�����������ͷ�ļ������Ҳ��������ڶ�������ⶨ�壬�ú���һ����������

// �����ⶨ����������һ��Ҫ�ں���������һ����������ģ��
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

