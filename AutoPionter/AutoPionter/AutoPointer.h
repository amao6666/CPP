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
	AutoPointer(AutoPointer& Other); // ��������
	AutoPointer(AutoPointer&& Other); // �ƶ����죬������ֵ����ʱ�ᱻ����
	~AutoPointer();

	int GetReferenceCount();

	AutoPointer<T>& operator=(const AutoPointer<T>&); // ���ظ�ֵ���������
	AutoPointer<T>& operator=(const AutoPointer<T>&&); // �����ƶ���ֵ���������

	// ����ָ�������
	T* operator -> () const
	{
		return BindPointer;
	}

	// ����ȡַ�����
	T operator* () const
	{
		return *BindPointer;
	}

	// �����������ת�����͵�bool
	operator bool()
	{
		return BindPointer != nullptr;
	}

	// ���Խ�int��ʽת����AutoPointer
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
		Other.BindPointer = nullptr; // ��ֹ��ֵ������ʱ���ü�����һ
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
	// �ͷžɵ�
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
		Other.BindPointer = nullptr; // ��ֹ��ֵ������ʱ���ü�����һ
	}
}
