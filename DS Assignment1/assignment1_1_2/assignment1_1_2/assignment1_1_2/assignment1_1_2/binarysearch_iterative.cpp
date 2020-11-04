#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int BinarySearch(int A[], int start, int end, int key)
{
	int nMid;
	int nEnd = end - 1;

	while (start <= nEnd) {
		nMid = (start + nEnd) / 2;

		if (key == A[nMid]) {
			return nMid;
		}
		else if (key > A[nMid]) {
			start = nMid + 1;
		}
		else {
			nEnd = nMid - 1;
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

	for (int i = 0; !in.eof(); i++) {
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
		cout << nResult << "번째 배열 요소에 있습니다." << endl; //배열은 0부터 시작하므로 0번째부터 시작됩니다.
	}

	in.close();

	return 0;
}