#include<iostream>
#include "BST.cpp"
using namespace std;

int main() {
	Nptr s = NULL;
	Nptr a = NULL;

	s = Insert(s, "ca");
	s = Insert(s, "ac");
	s = Insert(s, "java");
	s = Insert(s, "ad");
	s = Insert(s, "aa");
	s = Insert(s, "car");

	Display(s);
	cout << endl;

	char A[100];

	cout << "Search word : ";
	cin >> A;

	Nptr word = Search(s, A);
	if (word->Data.Key != "\0") cout << "Find : " << word->Data.Key << endl;

	cout << endl;

	cout << "Delete word : ";
	cin >> A;
	Delete(s, A);

	Display(s);
	cout << endl << endl;

	cout << "Insert word : ";
	cin >> A;

	Nptr word2 = Insert(s, A);

	Display(s);
	cout << endl << endl;

	cout << "Update word : ";
	cin >> A;
	Update(s, A);
	Display(s);
}