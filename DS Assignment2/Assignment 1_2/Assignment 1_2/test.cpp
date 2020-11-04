#include<iostream>
#include<time.h>
#include "mergesort.cpp"
#include "quicksort.cpp"
#define MAX 1000
using namespace std;

void main() {
	int arr[MAX];
	int arr2[MAX];

	srand((unsigned int)time(NULL));
	int x = rand() % 20;
	int y = rand() % 20;

	for (int i = 0; i < x; i++) {
		arr[i] = rand() % 31;
	}

	for (int i = 0; i < y; i++) {
		arr2[i] = rand() % 31;
	}

	cout << "Before : ";
	for (int j = 0; j < x; j++) {
		cout << arr[j] << " ";
	}

	cout << endl << endl;

	mergesort(arr, 0, x-1);

	cout << "After : ";
	for (int i = 0; i < x; i++) {
		cout << arr[i] << " ";
	}

	cout << endl << endl;

	cout << "Before : ";
	for (int j = 0; j < y; j++) {
		cout << arr2[j] << " ";
	}

	cout << endl << endl;

	quicksort(arr2, 0, y-1);

	cout << "After : ";
	for (int i = 0; i < y; i++) {
		cout << arr2[i] << " ";
	}

}