#include<iostream>
#include<time.h>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
#include "hash.cpp"
#include "BST.cpp"
#define MAX 100000
using namespace std;

static const char alpha[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int Length = sizeof(alpha) - 1;

char Random()
{
	return alpha[rand() % Length];
}


double getdtime() {
	struct timeval tv = { 0 };
	double dtime;
	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);

	return dtime;
}

int main(int argc, char **argv()) {
	const char *s = "Dickens_Oliver_1839.tokens.txt";
	
	Hash a;
	a.Open(s);

	double oldtime = getdtime();
	string s;

	srand((unsigned int)time(NULL));

	for (int i = MAX; i <= 10000000; i = MAX * 10)
	{
		for (int j = 0; j < i; j++)
		{
			s += Random();
			a.Search(s.c_str());
		}
		cout << "N= " << j << ", Hash" << ", ";
		cerr << "elapsed_time: " << elapsed_time << "sec" << endl;
	}

	cout << endl;

	ifstream in("Dickens_Oliver_1839.tokens.txt");
	Nptr T = NULL;
	Nptr n = NULL;
	string s2;
	vector<string> v;

	double oldtime2 = getdtime();
	string s3;

	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> s2;
			v.push_back(s2);
		}
	}
	string *a2 = new string[v.size()];

	for (int i = 0; i < v.size(); i++)
	{
		a2[i] = v[i];
		T = Insert(T, a2[i].c_str());
	}

	srand((unsigned int)time(NULL));
	for (int j = MAX; j <= 10000000; j = MAX * 10)
	{
		for (int i = 0; i < j; i++)
		{
			s3 += Random();
			n = Search(T, s3.c_str());
		}
		cout << "N= " << j << ", BST" << ", ";
		cerr << "elapsed_time: " << elapsed_time << "sec" << endl;
	}

}