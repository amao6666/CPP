#pragma once
#include "User.h"

class User1 : public User<int> // ����̳�ģ�����ϵ������ָ������ľ�������
{

};

template<typename _T>
class User2 : public User<_T> // ����ָ�������ģ�壬�������������ģ������
{

};