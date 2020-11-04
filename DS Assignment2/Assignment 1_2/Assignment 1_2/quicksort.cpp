#include<iostream>
using namespace std;

inline void Swap(int *A, int first, int last)
{
	int temp = A[first];
	A[first] = A[last];
	A[last] = temp;
}
inline int partition(int *A, int first, int last)
{
	int low, high, p;
	p = A[first];
	low = first + 1;
	high = last;

	while (low <= high)
	{
		while (p >= A[low] && low <= last) low++; 
		while (p <= A[high] && high >= (first + 1)) high--;
		if (low <= high)
			Swap(A, low, high);
	}

	Swap(A, first, high);

	return high;

}


inline void quicksort(int *A, int first, int last)
{
	if (first <= last)
	{
		int pivotIndex = partition(A, first, last);
		quicksort(A, first, pivotIndex - 1);
		quicksort(A, pivotIndex + 1, last);
	}
}