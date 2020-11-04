#include<iostream>
#include<fstream>
#include<stack>
#include<vector>

using namespace std;

int n, m;
bool **check, *visited;
stack<int> s;

void dfs(int v)
{
	if (visited[v])
		s.pop();
	else {
		visited[v] = true;
		cout << s.top() << " ";
		s.pop();
		for (int i = n; i >0; i--)
		{
			if (check[v][i] && !visited[i]) {
				s.push(i);
			}
		}
	}
	if (!s.empty()) {
		dfs(s.top());
	}
}

void input()
{
	ifstream inFile("sample_graph.txt");
	int a, b, file, count = 0;
	vector<int> v;

	for (int i = 0; !inFile.eof(); i++) {
		inFile >> file;
		v.push_back(file);
		count++;
	}

	int* A = &v[0];

	for (int i = 0; i < count; i++) {
		A[i] = v[i];
	}

	n = count/2;

	if (inFile.is_open())
	{
		check = new bool*[n + 1];
		visited = new bool[n + 1];
		for (int i = 1; i <= n; i++)
		{
			check[i] = new bool[n + 1];
			visited[i] = false;
			for (int j = 1; j <= n; j++)
			{
				check[i][j] = false;
			}
		}

		for (int i = 0; i < count; i+=2)
		{
			a = A[i];
			b = A[i + 1];
			check[a][b] = true;
			check[b][a] = true;
		}

	}
	inFile.close();
}

int main()
{
	int a, b;
	cout << "enter staring and ending vertices >";
	cin >> a >> b;

	int start = a;

	input();
	s.push(start);

	dfs(s.top());

	return 0;
}