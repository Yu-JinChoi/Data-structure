#include<iostream>
#include<fstream>
#include<string>
#define MAX 100000
#define MAX2 100
using namespace std;

void radix_sort(string *A, int n, int p)
{
	int i, pos = 1, *cnt;
	string *tmp;

	tmp = new string [n];
	cnt = new int [MAX2];

	while (--p >= 0)
	{
		for (i = 0; i < MAX2; i++) cnt[i] = 0;

		for (i = 0; i < n; i++) cnt[(A[i].length())]++;

		for (i = 1; i < MAX2; i++) cnt[i] += cnt[i - 1];

		for (i = n - 1; i >= 0; i--) tmp[--cnt[(A[i].length() / pos) % MAX2]] = A[i];

		memcpy(A, tmp, n * sizeof(int));
		pos *= MAX2;

		ofstream out("tokens.sorted.txt");

		for (int i = 0; i < MAX; i++) out << tmp[i] << endl;
	}

	delete[] tmp;
	delete[] cnt;
}

int main() {
	string *A = new string[MAX];

	ifstream in("C:\\Users\\LG\\Documents\\Visual Studio 2017\\Projects\\Assignment 1_3_2\\Assignment 1_3_2\\tokens.txt");

	if (in.is_open()) {
		for (int i = 0; !in.eof(); i++) {
			in >> A[i];
		}
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	radix_sort(A, MAX, 26);

	delete[] A;
	return 0;
}