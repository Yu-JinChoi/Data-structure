#include<iostream>
#include<time.h>
#define n 100
using namespace std;

inline void merge(int *A, int F, int Mid, int L) {
	int temp[n];
	int First1 = F;
	int Last1 = Mid;
	int First2 = Mid + 1;
	int Last2 = L;
	int Index = First1;

	for (; (First1 <= Last1) && (First2 <= Last2); ++Index)
	{
		if (A[First1] < A[First2]) {
			temp[Index] = A[First1];
			++First1;
		}
		else {
			temp[Index] = A[First2];
			++First2;
		}
	}
	for (; First1 <= Last1; ++First1, ++Index) temp[Index] = A[First1];
	for (; First2 <= Last2; ++First2, ++Index) temp[Index] = A[First2];
	for (Index = F; Index <= L; ++Index) A[Index] = temp[Index];
}

inline void mergesort(int *A, int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		mergesort(A, first, middle);
		mergesort(A, middle + 1, last);
		merge(A, first, middle, last);
	}
}