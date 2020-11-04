#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "Hash.cpp"
using namespace std;

int main()
{
	Hash A;
	
	A.Create(8);
	A.Insert("Hello");
	A.Insert("World");
	A.Insert("Nice");
	A.Insert("To");
	A.Insert("Meet");
	A.Insert("You");

	A.Display();

	A.Open("Open.txt");

	cout << endl << endl;

	A.Delete("World");
	A.Delete("Aa");

	A.Display();

	cout << endl << endl;

	A.Update("Good");

	A.Display();

	A.Save("Open2.txt");

	return 0;
}