#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#define MAX 100001
#define RAND_MAX 0x7fff
using namespace std;

void file(int *A) {
	float num[24];
	float file, file2;
	int num2[24];
	num[0] = 0;

	ifstream in("word_length_stat.txt");
	for (int i = 0; !in.eof(); i++) {
		if (i % 2 != 0) {
			in >> file2;
			num[(i / 2) + 1] = file2;
		}
		else in >> file;
	}

	for (int i = 1; i < 24; i++) num[i] = num[i] * 1000;
	for (int i = 1; i < 24; i++) num[i] += num[i - 1];
	for (int i = 0; i < 24; i++) num2[i] = (int)num[i];

	for (int i = 1; i < 24; i++) {
		for (int j = (int)num[i - 1]; j < MAX; j++) {
			if ((num2[i] > j) && !(num2[i]==num2[i-1])) A[j] = i;
		}
	}
}

int main() {
	int A[MAX];
	int n = 0;

	ofstream out("tokens.txt");
	ofstream out2("tokens2.txt");
	ofstream out3("tokens3.txt");

	file(A);
	srand(time(NULL));
	while (n < 100000) {
		int x = (rand() / (float)RAND_MAX * 100000.f) + 1;
		int length = A[x];
		for (int i = 0; i < length; i++) {
			int t = rand() % 26;
			char a = t + 97;
			if (out.is_open()) out << a;
		}
		out << endl;
		n++;
	}

	n = 0;
	while (n < 10000) {
		int x = (rand() / (float)RAND_MAX * 100000.f) + 1;
		int length = A[x];
		for (int i = 0; i < length; i++) {
			int t = rand() % 26;
			char a = t + 97;
			if (out2.is_open()) out2 << a;
		}
		out2 << endl;
		n++;
	}

	n = 0;
	while (n < 1000000) {
		int x = (rand() / (float)RAND_MAX * 100000.f) + 1;
		int length = A[x];
		for (int i = 0; i < length; i++) {
			int t = rand() % 26;
			char a = t + 97;
			if (out3.is_open()) out3 << a;
		}
		out3 << endl;
		n++;
	}
}