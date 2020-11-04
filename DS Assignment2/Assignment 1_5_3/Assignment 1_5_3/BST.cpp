#include<iostream>
#include<string>
using namespace std;

typedef struct dataRecord
{
	string Key;
	int count = 0;
}dataType;

typedef struct treeRecord
{
	dataType Data;
	struct treeRecord *LChild;
	struct treeRecord *RChild;
}node;

typedef node* Nptr;

inline Nptr Search(Nptr T, const char *key) {
	if (T == NULL) cout << "No Such Node" << endl;
	else if (T->Data.Key == key)
		return T;
	else if (T->Data.Key > key)
		return Search(T->LChild, key);
	else
		return Search(T->RChild, key);
}

inline void Update(Nptr &T, const char *key) {
	if (T == NULL) {
		T = new node;
		T->Data.Key = key;
		T->Data.count = 1;
		T->LChild = NULL;
		T->RChild = NULL;
	}
	else if (T->Data.Key == key)
		T->Data.count += 1;
	else if (T->Data.Key > key)
		Update(T->LChild, key);
	else
		Update(T->RChild, key);
}

inline Nptr Insert(Nptr T, const char *key) {
	if (T == NULL) {
		T = new node;
		T->Data.Key = key;
		T->LChild = NULL;
		T->RChild = NULL;
	}
	else if (T->Data.Key > key)
		T->LChild = Insert(T->LChild, key);
	else if (T->Data.Key == key) {
		T->Data.count += 1;
	}
	else
		T->RChild = Insert(T->RChild, key);

	return T;
}

inline void SuccessorCopy(Nptr& T, dataType& DelNodeData) {
	if (T->LChild == NULL) {
		DelNodeData.Key = T->Data.Key;
		Nptr Temp = T;
		T = T->RChild;
		delete Temp;
	}
	else
		SuccessorCopy(T->LChild, DelNodeData);
}

inline void Delete(Nptr &T, const char *key) {
	if (T == NULL)
		cout << "No Record with Such Key" << endl;
	else if (T->Data.Key > key)
		Delete(T->LChild, key);
	else if (T->Data.Key < key)
		Delete(T->RChild, key);
	else if (T->Data.Key == key) {
		if ((T->LChild == NULL) && (T->RChild == NULL)) {
			T = NULL;
			delete T;
		}
		else if (T->LChild == NULL) {
			Nptr Temp = T;
			T = T->RChild;
			delete Temp;
		}
		else if (T->RChild == NULL) {
			Nptr Temp = T;
			T = T->LChild;
			delete Temp;
		}
		else
			SuccessorCopy(T->RChild, T->Data);
	}
}

inline void Display(Nptr T)
{
	if (T == NULL)
		return;

	Display(T->LChild);
	cout << T->Data.Key << " " << T->Data.count << endl;
	Display(T->RChild);
}