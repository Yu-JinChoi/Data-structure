#include <iostream>
#include <string>
#include "genericStackDL.h"
#include "genericStackDL.cpp"
using namespace std;

int main()
{
	int Item;
	double Item2;
	string Item3;

	stackClass<int> s;

	s.Push(10);
	s.Push(40);
	s.Push(60);
	s.Push(30);
	s.Push(45);
	s.Push(75);

	s.Display();

	s.GetTop(Item);
	s.Retrieve2(3, Item);
	s.Pop();

	s.Display();
	cout << endl;

	stackClass<double> s2;

	s2.Pop();
	s2.Push(0.1);
	s2.Push(0.4);
	s2.Push(0.6);
	s2.Push(0.3);
	s2.Push(0.45);
	s2.Push(0.75);

	s2.Display();

	s2.GetTop(Item2);
	s2.Retrieve2(0, Item2);
	s2.Pop();

	s2.Display();
	cout << endl;

	stackClass<string> s3;

	s3.Push("Hello");
	s3.Push("world");
	s3.Push("nice");
	s3.Push("to");
	s3.Push("meet");
	s3.Push("you");

	s3.Display();

	s3.GetTop(Item3);
	s3.Retrieve2(5, Item3);
	s3.Pop();

	s3.Display();

	return 0;
}