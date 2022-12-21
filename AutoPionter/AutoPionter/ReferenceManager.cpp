#include <iostream>
#include "ReferenceManager.h"
using namespace std;

ReferenceManager::ReferenceManager()
{
	PointerCounterHead = nullptr;
	PointerCounterTail = nullptr;
}

ReferenceManager* ReferenceManager::GetInstance()
{
	if (!ReferenceManager::_instance)
	{
		ReferenceManager::_instance = new ReferenceManager;
	}
	return ReferenceManager::_instance;
}

void ReferenceManager::AddReferencePointer(void* Pointer)
{
	if (!PointerCounterHead)
	{
		PointerCounterHead = GeneratePointerCounter(Pointer);
		PointerCounterTail = PointerCounterHead;
		return;
	}

	if (FPointerCounter* Temp = FindPointerCounter(Pointer))
	{
		Temp->Count++;
		return;
	}

	if (PointerCounterTail)
	{
		FPointerCounter* NewPointerCounter = GeneratePointerCounter(Pointer);
		PointerCounterTail->Next = NewPointerCounter;
		NewPointerCounter->Prev = PointerCounterTail;
		PointerCounterTail = NewPointerCounter;
		return;
	}
}

int ReferenceManager::RemoveReferencePointer(void* Pointer)
{
	if (FPointerCounter* Temp = FindPointerCounter(Pointer))
	{
		Temp->Count--;
		if (Temp->Count <= 0)
		{
			RemoveNode(Temp);
		}
		else
		{
			return Temp->Count;
		}
	}
	return 0;
}

int ReferenceManager::GetPointerCount(void* Pointer)
{
	if (FPointerCounter* Temp = FindPointerCounter(Pointer))
	{
		return Temp->Count;
	}
	return 0;
}

FPointerCounter* ReferenceManager::FindPointerCounter(void* Pointer)
{
	if (PointerCounterHead)
	{
		FPointerCounter* Temp = PointerCounterHead;
		while (Temp)
		{
			if (Temp->ReferencePointer == Pointer)
			{
				return Temp;
			}
			else
			{
				Temp = Temp->Next;
			}
		}
	}
	return nullptr;
}

void ReferenceManager::RemoveNode(FPointerCounter* Node)
{
	if (Node == PointerCounterHead)
	{
		if (PointerCounterTail == PointerCounterHead) PointerCounterTail = nullptr;
		PointerCounterHead = PointerCounterHead->Next;
		if (PointerCounterHead) PointerCounterHead->Prev = nullptr;
		delete Node;
	}
	else
	{
		if (Node == PointerCounterTail)
		{
			PointerCounterTail = Node->Prev;
			Node->Prev->Next = nullptr;
		}
		else
		{
			Node->Prev->Next = Node->Next;
			Node->Next->Prev = Node->Prev;
		}
		delete Node;
	}
}

FPointerCounter* ReferenceManager::GeneratePointerCounter(void* Pointer)
{
	FPointerCounter* PointerCounter = new FPointerCounter;
	PointerCounter->Count = 1;
	PointerCounter->ReferencePointer = Pointer;
	return PointerCounter;
}
