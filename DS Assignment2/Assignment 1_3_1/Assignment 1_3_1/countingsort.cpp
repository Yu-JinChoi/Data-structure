#include <iostream>
#define MAX 100
using namespace std;

inline void countingsort(int *A, int size, int k) {
    int count[MAX]={0};
	int result[MAX];

	for(int i=0; i<size; i++) {
		count[A[i]]++;
	}
    
	for (int i=1; i<k; i++) {
		count[i] += count[i - 1];
	}
    
    for(int i=0; i<size; i++) {
		result[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }
    
	for (int i = 0; i < size; i++) {
		A[i] = result[i];
	}
}