#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<string>
#include "Hash.cpp"
using namespace std;

int main() {
	const char *A = "The-Road-Not-Taken.tokens.txt";
	const char *A2 = "Dickens_Oliver_1839.tokens.txt";
	const char *B = "The-Road-Not-Taken.hash.txt";
	const char *B2 = "Dickens_Oliver_1839.hash.txt";

	Hash a;

	a.Open(A);
	a.Save(B);

	a.Open(A2);
	a.Save(B2);

	return 0;
}