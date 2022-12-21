#pragma once
#include "User.h"

class User1 : public User<int> // 如果继承模板类关系，必须指定父类的具体类型
{

};

template<typename _T>
class User2 : public User<_T> // 可以指定子类的模板，重新声明父类的模板类型
{

};