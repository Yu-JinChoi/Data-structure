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

	cout << "ã���� �ϴ� ���ڸ� �Է����ּ��� : ";
	cin >> n;
	cout << "������ ���� ��Ʈ�� ���� �Է��ϼ��� : ";
	cin >> k;

	nResult = KarySearch(A, k, 0, count-1, n);

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