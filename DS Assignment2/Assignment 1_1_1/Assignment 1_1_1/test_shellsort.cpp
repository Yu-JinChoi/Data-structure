#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "shellsort.h"
using namespace std;

int main()
{
	int n;
	int num[10];

	cout << "Input Array size : ";
	cin >> n;

	int *A = new int[n];

	srand(time(0));

	cout << "Before : " << endl;

	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % (2 * n);
		cout << A[i] << " ";
	}
	cout << endl;

	shellsort(A, n, 3);

	cout << "After : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;

	ifstream in("input.txt");

	for (int i = 0; !in.eof(); i++)
	{
		in >> num[i];
	}

	cout << "Before File :" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;

	cout << "After File : " << endl;

	shellsort(num, 10, 3);

	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ";
	}

	return 0;
}