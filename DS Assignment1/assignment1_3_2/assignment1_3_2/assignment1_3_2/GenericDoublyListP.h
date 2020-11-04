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