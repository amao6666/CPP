#pragma once

struct FPointerCounter
{
	void* ReferencePointer;
	int Count;
	FPointerCounter* Next;
	FPointerCounter* Prev;
	FPointerCounter() : Next(nullptr), Prev(nullptr), Count(0), ReferencePointer(nullptr) {};
};

class ReferenceManager
{
	ReferenceManager();
	static ReferenceManager* _instance;
	FPointerCounter* PointerCounterHead;
	FPointerCounter* PointerCounterTail;

public:
	static ReferenceManager* GetInstance();
	void AddReferencePointer(void* Pointer);
	int RemoveReferencePointer(void* Pointer);
	int GetPointerCount(void* Pointer);

private:
	FPointerCounter* GeneratePointerCounter(void* Pointer);
	FPointerCounter* FindPointerCounter(void* Pointer);
	void RemoveNode(FPointerCounter* Node);
};


