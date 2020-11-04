#include <iostream>
#include <cstdlib>
#include <ctime>
#include "shellsort_sedgewic.h"
#include "shellsort.h"
using namespace std;

int main()
{
	int a;
	cout << "Input > ";
	cin >> a;

	int *A = new int[a];
	int *B = new int[a];
	srand((unsigned int)time(0));

	cout << "Before : ";
	for (int i = 0; i < a; i++)
	{
		A[i] = rand() % 60;
		B[i] = A[i];
		cout << A[i] << " ";
	}
	cout << endl << endl;

	shellsort_sedgewick(A, a);
	shellsort(B, a, 3);
	cout << "sedgewick After : ";
	for (int i = 0; i < a; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "Pratt After : ";
	for (int i = 0; i < a; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

	return 0;
}