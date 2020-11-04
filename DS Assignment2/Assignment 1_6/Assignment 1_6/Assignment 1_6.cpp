#include<iostream>
using namespace std;

inline void swap(int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

inline void build_heap(int *A, int size) {
	int i;

	for (i = 2; i <= size; i++) {
		for (int j = i; j > 1; j = j / 2) {
			if (A[j] > A[j / 2]) swap(A[j], A[j / 2]);
			else break;
		}
	}
}