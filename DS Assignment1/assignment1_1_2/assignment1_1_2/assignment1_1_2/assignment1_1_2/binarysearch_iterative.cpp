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

	cout << "ã���� �ϴ� ���ڸ� �Է����ּ��� : ";
	cin >> n;

	nResult = BinarySearch(A, 0, count, n);

	if (nResult == -1)
	{
		cout << "���� �����ϴ�.\n";
	}
	else
	{
		cout << nResult << "��° �迭 ��ҿ� �ֽ��ϴ�." << endl; //�迭�� 0���� �����ϹǷ� 0��°���� ���۵˴ϴ�.
	}

	in.close();

	return 0;
}