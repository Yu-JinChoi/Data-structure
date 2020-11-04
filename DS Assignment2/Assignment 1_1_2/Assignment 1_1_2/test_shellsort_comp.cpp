#include<iostream>
#include<time.h>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
#include "shellsort.h"
#define MAX 1000
using namespace std;

double getdtime() {
	struct timeval tv = { 0 };
	double dtime;

	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);

	return dtime;
}


int main(int argc, char **argv) {

	int x, N[1000000];
	int K = 1;
	double oldtime = getdtime();

	srand((unsigned int)time(NULL));
	for (int i = MAX; i <= 1000000; i = MAX * 10) {
		for (int t = 0; t < i; t++) {
			x = rand() % 50;
			N[t] = x;
		}
		for (int j = K; j < 4; j++) {
			shellsort(N, i, j);
			for (int y = 0; y<i; y++) { usleep(i); }
			double elapsed_time = getdtime() - oldtime;

			cout << "N=" << i << ", K=" << j << ", ";
			cerr << "elapsed_time: " << elapsed_time << " sec" << endl;
		}
	}

	return 1;
}