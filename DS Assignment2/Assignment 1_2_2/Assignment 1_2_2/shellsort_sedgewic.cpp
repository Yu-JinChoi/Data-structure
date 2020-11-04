#include <cmath>

void insertionsort2(int *A, int size, int start, int h)
{
	int tmp, j;
	for (int i = start + h; i < size; i += h)
	{
		tmp = A[i];
		for (j = i - h; j >= start && A[j] > tmp; j -= h)
		{
			A[j + h] = A[j];
		}
		A[j + h] = tmp;
	}
}

void shellsort_sedgewick(int *A, int size)
{
	int i, h;

	for (i = 0; pow((int)4.0, i + 1) + 3 * pow((int)2.0, i) + 1 < size; i++)
		i--;

	while (i >= 0)
	{
		if (i == 0) h = 1;
		else
			h = (pow((int)4.0, i) + 3 * pow((int)2.0, i - 1) + 1);

		insertionsort2(A, size, i, h);
		i--;
	}

}