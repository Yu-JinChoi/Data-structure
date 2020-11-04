#pragma once
template <typename T>
struct nodeRecord
{
	T Data;
	nodeRecord* Prev;
	nodeRecord* Next;
};

template <typename T>
class listClass
{
public:
	listClass();
	listClass(const listClass<T> &L);
	~listClass();
	void Insert(int Position, T Item);
	void Delete(int Position);
	void Display();
	void Retrieve(int Position, T & item);
	bool isEmpty();
	int Length();
private:
	int Count;
	nodeRecord<T> *Head;
	nodeRecord<T> *Tail;
};

template <typename T>
class stackClass {
public:
	stackClass();
	stackClass(const stackClass<T>& S);
	~stackClass();
	void Push(T Item);
	void Pop();
	void Display();
	void GetTop(T& Item);
	void Retrieve2(int Position, T& Item);
	bool IsEmpty();
private:
	listClass <T> L;
};