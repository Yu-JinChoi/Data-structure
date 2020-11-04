#include<iostream>
#include<time.h>
#include "countingsort.cpp"
#define MAX 25
using namespace std;

int main() {

	int A[MAX];
	int num, k = 10;

	srand((unsigned int)time(0));
	int n = rand() % 20 + 5;

	for (int i = 0; i < n; i++) {
		num = rand() % 10;
		A[i] = num;
	}

	cout << "Before : ";
	for (int i = 0; i < n; i++) cout << A[i] << ' ';

	cout << endl << endl;

	countingsort(A, n, k);

	cout << "After : ";
	for (int i = 0; i < n; i++) cout << A[i] << ' ';
	cout << endl;

	return 0;
}