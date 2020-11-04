#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int KarySearch(int A[], int k, int start, int end, int key) {

	while (start <= end) {
		if (A[start] == key) {
			return start;
		}
		else if (A[end] == key) {
			return end;
		}
		else if (key < A[start] || key > A[end]) {
			return -1;
		}
		else {
			for (int i = 0; i < k; i++) {
				if (A[start + (end - start) * i / k] <= key && key <= A[start + ((end - start) * (i + 1) / k)]) {
					cout << start << " " << end << endl;
					start++;
					KarySearch(A, k, start + (end - start) * i / k, start + ((end - start) * (i + 1) / k), key);
					break;
				}
			}
		}
	}
	return -1;
}

int main() {
	ifstream in("input.txt");
	int nResult, n, k, count = 0;
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
	cout << "나누고 싶은 파트의 수를 입력하세요 : ";
	cin >> k;

	nResult = KarySearch(A, k, 0, count-1, n);

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