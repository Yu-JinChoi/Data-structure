#include<iostream>
#include<fstream>
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
	if (T == NULL) cout << "No found" << endl;
	else if (T->Data.Key == key)
		return T;
	else if (T->Data.Key > key)
		return Search(T->LChild, key);
	else
		return Search(T->RChild, key);
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
	}
	else
		T->RChild = Insert(T->RChild, key);

	return T;
}

inline void Display(Nptr T)
{
	if (T == NULL)
		return;

	Display(T->LChild);
	cout << T->Data.Key << " " << T->Data.count << endl;
	Display(T->RChild);
}