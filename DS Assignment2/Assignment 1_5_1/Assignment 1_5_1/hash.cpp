#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<string>
#include "hash.h"
using namespace std;

inline Hash::Hash() {
	this->table = table;
	this->size = size;
}

inline void Hash::Create(int tablesize) {
	this->size = tablesize;
	this->table = new Nptr[tablesize];
	
	for (int i = 0; i < tablesize; i++) {
		table[i] = NULL;
	}
}

inline int strhashfunc(const char *key)
{
	char *str = (char*)key;
	unsigned int hashval = 0;

	for (hashval = 0; *str; str++)
	{
		hashval = *str + (hashval << 5) - hashval;
	}

	return hashval;
}

inline void Hash::Insert(const char *key) {
	int n = strhashfunc(key) % 12;
	Nptr p = new node;
	
	p->Data.Key = key;
	p->Data.count = 1;
	p->next = NULL;

	if (!table[n]) {
		p->next = table[n];
		table[n] = p;
	}
	else {
		table[n] = p;
		table[n]->next = NULL;
	}
}

inline Nptr Hash::Search(const char *key) {
	int n = strhashfunc(key) % 12;
	Nptr A = table[n];

	if (A == NULL) {
		cout << "No Such Node" << endl;
		return NULL;
	}
	else {
		while (A->next) {
			if (A->next->Data.Key == key) {
				return A->next;
			}
			A = A->next;
		}
	}
	return NULL;
}

inline void Hash::Update(const char *key) {
	int n = strhashfunc(key) % 12;
	
	if (table[n] == NULL) {
		table[n]->Data.Key = key;
		Update(key);
	}
	else if (table[n]->Data.Key == key) {
		table[n]->Data.count++;
	}
	else {
		table[n] = table[n]->next;
		Update(key);
	}

	cout << key << " " << table[n]->Data.count << endl;
}

inline void Hash::Delete(const char* key) {
	int n = strhashfunc(key) % 12;
	
	if (table[n] == NULL) {
		cout << "No Node" << endl;
		return;
	}

	Nptr A = NULL;

	if (table[n]->Data.Key == key) {
		A = table[n];
		table[n] = table[n]->next;
	}
	else {
		Nptr A2 = table[n];
		Nptr a = A2->next;
		
		while (a) {
			if (a->Data.Key == key) {
				A2->next = a->next;
				A = a;
				break;
			}
			A2 = a;
			a = A2->next;
		}
	}
}

inline void Hash::Save(const char* filename) {
	ofstream out(filename, ios::app);

	for (int i = 0; i < size; i++) {
		out << table[i]->Data.Key << " " << table[i]->Data.Key << endl;
	}
}

inline void Hash::Open(const char* filename) {
	string file;
	vector<string> v;

	ifstream in(filename);

	if (in.is_open()) {
		while (!in.eof()) {
			in >> file;
			v.push_back(file);
		}
	}
	else {
		cout << "No file" << endl;
		return;
	}
	
	string *a = new string[v.size()];

	for (int i = 0; i < v.size(); i++) {
		a[i] = v[i];
		Insert(a[i].c_str());
		Update(a[i].c_str());
	}
}

inline void Hash::Rehash(int newtablesize) {
	Nptr *A = new Nptr[newtablesize];
	
	for (int i = 0; i < newtablesize; i++) {
		A[i] = NULL;
	}

	for (int i = 0; i < size; i++) {
		Nptr A2 = table[i];

		while (A) {
			Insert(A2->Data.Key.c_str());
			A2 = A2->next;
		}
	}

	this->size = newtablesize;
	this->table = A;
}

inline void Hash::Display() {
	for (int i = 0; i < size; i++) {
		
		cout << "Index : " << i << " ";
		
		if (table[i] != NULL) {
			Nptr A = table[i];
			
			if (A != NULL) {
				cout << A->Data.Key << " " << A->Data.count;
				A = A->next;
			}
		}
		cout << endl;
	}
}