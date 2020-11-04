#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int BinarySearch(int A[], int start, int end, int key)
{
	int nMid;

	while (start <= end) {
		nMid = (start + end) / 2;

		if (key == A[nMid]) {
			return nMid;
		}
		else if (key < A[nMid]) {
			return BinarySearch(A, start, nMid - 1, key);
		}
		else {
			return BinarySearch(A, nMid + 1, end, key);
		}
	}
	return -1;
}

int main()
{
	ifstream in("input.txt");
	int nResult, n, count = 0;
	int file;
	vector<int> v;

	for (int i=0; !in.eof(); i++) {
		in >> file;
		v.push_back(file);
		count++;
	}

	int* A = &v[0];

	for (int i = 0; i < count; i++) {
		A[i] = v[i];
	}

	cout << "찾고자 하는 숫자를 입력해주세요 : ";
	cin >> n;

	nResult = BinarySearch(A, 0, count, n);

	if (nResult == -1)
	{
		cout << "값이 없습니다.\n";
	}
	else
	{
		cout << nResult << "번째 배열 요소에 있습니다." << endl;
	}

	in.close();

	return 0;
}