#include<iostream>
#include<string>
#include<vector>
#include "BST.cpp"
using namespace std;

int main() {
	string filename;

	cout << "BST\_word\_count\_test The-Road-Not-Taken.wordcount" << endl;

	ifstream in("C:\\Users\\LG\\Documents\\Visual Studio 2017\\Projects\\Assignment 1_4_2\\Assignment 1_4_2\\The-Road-Not-Taken.wordcount.txt");
	
	vector < string > v;
	vector < string > a;
	vector < int > v2;
	vector < int > a2;
	string file;
	int num;
	char A[100];
	Nptr s = NULL;

	if (in.is_open()) {
		cout << "Loading is complete" << endl;

		for (int i = 0; !in.eof(); i++) {
			in >> file;
			in >> num;
			v.push_back(file);
			v2.push_back(num);
		}

		string *temp = new string[v2.size()];

		for (int i = 0; i < v2.size(); i++) {
			temp[i] = v[i];
			s = Insert(s, temp[i].c_str());
			Search(s, temp[i].c_str())->Data.count = v2[i];
		}
	}
	else
		cout << "No file" << endl;

	int t = 0;
	while (t<10) {
		cout << "input> ";
		cin >> A;

		Nptr word = Search(s, A);
		if (word->Data.Key != "\0") cout << word->Data.count << endl;
		t++;
	}
	cout << "Finish!" << endl <<  endl;

	cout << "BST\_word\_count\_test Dickens_Oliver_1839.wordcount" << endl;

	ifstream in2("C:\\Users\\LG\\Documents\\Visual Studio 2017\\Projects\\Assignment 1_4_2\\Assignment 1_4_2\\Dickens_Oliver_1839.wordcount.txt");

	if (in2.is_open()) {
		cout << "Loading is complete" << endl;

		for (int i = 0; !in2.eof(); i++) {
			in2 >> file;
			in2 >> num;
			a.push_back(file);
			a2.push_back(num);
		}

		string *temp2 = new string[a2.size()];

		for (int i = 0; i < a2.size(); i++) {
			temp2[i] = a[i];
			s = Insert(s, temp2[i].c_str());
			Search(s, temp2[i].c_str())->Data.count = a2[i];
		}
	}
	else
		cout << "No file" << endl;

	while (1) {
		cout << "input> ";
		cin >> A;

		Nptr word = Search(s, A);
		if (word->Data.Key != "\0") cout << word->Data.count << endl;
	}
}