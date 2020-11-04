#include<iostream>
#include<time.h>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
#include "shellsort.h"
#include "shellsort_sedgewic.h"
#include "mergesort.cpp"
#include "quicksort.cpp"
#define MAX 1000
using namespace std;

double getdtime() { 
	struct timeval tv = {0};
	double dtime;
	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	
	return dtime;
}

int main() {
	int x, N[1000000];
	int K = 1;
	double oldtime = getdtime();

	srand((unsigned int)time(NULL));
	for (int i = MAX; i <= 1000000; i = MAX * 10) {
		for (int t = 0; t < i; t++) {
			x = rand() % 50;
			N[t] = x;
		}

			for (int y = 0; y<i; y++) { shellsort(N, i, 3); usleep(i); }
			double elapsed_time = getdtime() - oldtime;

			cout << "N=" << i << ", Shellsort-Pratt, K=3, ";
			cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

			for (int y = 0; y<i; y++) { shellsort_sedgewick(N, i); usleep(i); }
			double elapsed_time = getdtime() - oldtime;

			cout << "N=" << i << ", Shellsort-Sedgewick, ";
			cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

			for (int y = 0; y<i; y++) { mergesort(N, 0, i - 1); usleep(i); }
			double elapsed_time = getdtime() - oldtime;

			cout << "N=" << i << ", Mergesort, ";
			cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

			for (int y = 0; y<i; y++) { quicksort(N, 0, i - 1); usleep(i); }
			double elapsed_time = getdtime() - oldtime;

			cout << "N=" << i << ", Quicksort, ";
			cerr << "elapsed_time: " << elapsed_time << " sec" << endl;
	}

	return 1;
}
