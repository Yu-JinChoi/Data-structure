#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#define MAX_WORD_SIZE 25
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define MAX 100000
using namespace std;

typedef struct {
	char word[MAX_WORD_SIZE] = { '\0' };
}element;

element list[MAX];
int n;

int compare(element e1, element e2) {
	return strcmp(e1.word, e2.word);
}

int partition(element list[], int left, int right) {
	element pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do
			low++;
		while (compare(list[low], pivot) < 0);
		do
			high--;
		while (compare(list[high], pivot) > 0);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(element list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

void insert(element e) {
	if (n < (MAX - 1))
		list[n++] = e;
}

int main() {
	string A;
	element e;

	ifstream in("C:\\Users\\LG\\Documents\\Visual Studio 2017\\Projects\\Assignment 1_3_2\\Assignment 1_3_2\\tokens.txt");

	if (in.is_open()) {
		for (int i = 0; !in.eof(); i++) {
			in >> A;
			for (int j = 0; j < A.length(); j++)
				e.word[j] = A.at(j);
			insert(e);
		}
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	quick_sort(list, 0, MAX);

	ofstream out("tokens.exhange sorted.txt");

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j<20; j++) out << list[i].word[j];
		out << endl;
	}

	return 0;
}