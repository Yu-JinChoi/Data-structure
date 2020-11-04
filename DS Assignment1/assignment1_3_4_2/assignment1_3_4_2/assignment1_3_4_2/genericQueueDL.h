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
class queueClass {
public:
	queueClass();
	queueClass(const queueClass<T> &Q);
	~queueClass();
	void Add(T Item);
	void Remove();
	void Display();
	void GetFront(T& Item);
	void Retrieve3(int Position, T& Item);
	bool IsEmpty();
private:
	listClass <T> Rear;
};