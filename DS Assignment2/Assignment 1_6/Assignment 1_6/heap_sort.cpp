#include<iostream>
#include<time.h>
#include "Assignment 1_6.cpp"
#define MAX 100
using namespace std;

int remove_heap(int *A, int size) {
	int root;
	int i = 1;

	root = A[1];
	A[1] = A[size];
	size--;

	build_heap(A, size);

	return root;
}

int main() {
	int A[MAX];
	int n;

	srand((unsigned int)time(NULL));
	n = rand() % 15 + 3;

	A[0] = 0;
	for (int i = 1; i <= n; i++) {
		A[i] = rand() % 100;
	}

	cout << "Before : ";
	for (int i = 1; i <= n; i++) cout << A[i] << " ";
	cout << endl;

	build_heap(A, n);

	cout << "After : ";
	for (int i = 1; i <= n; i++) cout << A[i] << " ";
	cout << endl << endl;

	cout << "Remove value : ";
	for (int i = n; i >= 1; i--) {
		cout << remove_heap(A, i) << " ";
	}
	cout << endl << endl;
}