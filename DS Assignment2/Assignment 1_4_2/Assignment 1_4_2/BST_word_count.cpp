#include<iostream>
#include<fstream>
#include<string>
#include<vector>
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

void Update(Nptr &T, const char *key) {
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
	else if (T->Data.Key == key) {
		T->Data.count += 1;
	}
	else
		Update(T->RChild, key);
}

Nptr Insert(Nptr T, const char *key) {
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

void Display(Nptr T, string filename)
{

	ofstream out(filename + ".txt", ios::app);
	if (T == NULL)
		return;

	Display(T->LChild, filename);
	out << T->Data.Key << " " << T->Data.count << endl;
	Display(T->RChild, filename);

}

int main() {
	string file;
	vector<string> v;
	vector<string> v2;
	Nptr s = NULL;
	Nptr s2 = NULL;

	ifstream in("The-Road-Not-Taken.tokens.txt");
	ifstream in2("Dickens_Oliver_1839.tokens.txt");

	for (int i = 0; !in.eof(); i++) {
		in >> file;
		v.push_back(file);
	}

	for (int i = 0; !in2.eof(); i++) {
		in2 >> file;
		v2.push_back(file);
	}

	string *temp = new string[v.size()];
	string *temp2 = new string[v2.size()];

	for (int i = 0; i < v.size(); i++) {
		temp[i] = v[i];
		s = Insert(s, temp[i].c_str());
		Update(s, temp[i].c_str());
	}

	for (int i = 0; i < v2.size(); i++) {
		temp2[i] = v2[i];
		s2 = Insert(s2, temp2[i].c_str());
		Update(s2, temp2[i].c_str());
	}

	Display(s, "The-Road-Not-Taken.wordcount");
	Display(s2, "Dickens_Oliver_1839.wordcount");

}