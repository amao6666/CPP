#pragma once
#include "ReferenceManager.h"
#include <iostream>
using namespace std;

template<typename T>
class AutoPointer
{
	T* BindPointer;
	
	void Release();
	void ManagerBindPointer();

public:
	AutoPointer();
	AutoPointer(T* pointer);
	AutoPointer(AutoPointer& Other); // 拷贝构造
	AutoPointer(AutoPointer&& Other); // 移动构造，发生右值拷贝时会被调用
	~AutoPointer();

	int GetReferenceCount();

	AutoPointer<T>& operator=(const AutoPointer<T>&); // 重载赋值拷贝运算符
	AutoPointer<T>& operator=(const AutoPointer<T>&&); // 重载移动赋值拷贝运算符

	// 重载指针运算符
	T* operator -> () const
	{
		return BindPointer;
	}

	// 重载取址运算符
	T operator* () const
	{
		return *BindPointer;
	}

	// 重载运算符，转换类型到bool
	operator bool()
	{
		return BindPointer != nullptr;
	}

	// 可以将int隐式转换成AutoPointer
	AutoPointer(int) {};
};

template<typename T>
inline void AutoPointer<T>::Release()
{
	if (BindPointer)
	{
		int count = ReferenceManager::GetInstance()->RemoveReferencePointer(BindPointer);
		if (count <= 0)
		{
			delete BindPointer;
			BindPointer = nullptr;
		}
	}
}

template<typename T>
inline void AutoPointer<T>::ManagerBindPointer()
{
	if (BindPointer)
	{
		ReferenceManager::GetInstance()->AddReferencePointer(BindPointer);
	}
}

template<typename T>
inline AutoPointer<T>::AutoPointer()
{
	BindPointer = nullptr;
}

template<typename T>
inline AutoPointer<T>::AutoPointer(T* pointer)
{
	BindPointer = pointer;
	ManagerBindPointer();
}

template<typename T>
inline AutoPointer<T>::AutoPointer(AutoPointer& Other)
{
	if (Other.BindPointer)
	{
		ReferenceManager::GetInstance()->AddReferencePointer(Other.BindPointer);
		BindPointer = Other.BindPointer;
	}
}

template<typename T>
inline AutoPointer<T>::AutoPointer(AutoPointer&& Other)
{
	if (Other.BindPointer)
	{
		BindPointer = Other.BindPointer;
		Other.BindPointer = nullptr; // 防止右值被回收时引用计数减一
	}
}

template<typename T>
inline AutoPointer<T>::~AutoPointer()
{
	if (BindPointer)
	{
		Release();
	}
}

template<typename T>
inline int AutoPointer<T>::GetReferenceCount()
{
	if (BindPointer)
	{
		return ReferenceManager::GetInstance()->GetPointerCount(BindPointer);
	}
	return 0;
}

template<typename T>
inline AutoPointer<T>& AutoPointer<T>::operator=(const AutoPointer<T>& Other)
{
	// 释放旧的
	Release();
	BindPointer = Other.BindPointer;
	ManagerBindPointer();
	return *this;
}

template<typename T>
inline AutoPointer<T>& AutoPointer<T>::operator=(const AutoPointer<T>&& Other)
{
	if (Other.BindPointer)
	{
		BindPointer = Other.BindPointer;
		Other.BindPointer = nullptr; // 防止右值被回收时引用计数减一
	}
}
