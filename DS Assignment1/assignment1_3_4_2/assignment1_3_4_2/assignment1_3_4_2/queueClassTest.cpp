#include<iostream>
#include <string>
#include "genericQueueDL.h"
#include "genericQueueDL.cpp"
using namespace std;

int main() {
	int Item;
	double Item2;
	string Item3;

	queueClass<int> s;

	s.Add(10);
	s.Add(40);
	s.Add(60);
	s.Add(30);
	s.Add(45);
	s.Add(75);

	s.Display();

	s.GetFront(Item);
	s.Retrieve3(3, Item);
	s.Remove();

	s.Display();
	cout << endl;

	queueClass<double> s2;

	
	s2.Add(0.1);
	s2.Add(0.4);
	s2.Add(0.6);
	s2.Add(0.3);
	s2.Add(0.45);
	s2.Add(0.75);

	s2.Display();

	s2.GetFront(Item2);
	s2.Retrieve3(0, Item2);
	s2.Remove();

	s2.Display();
	cout << endl;

	queueClass<string> s3;

	s3.Remove();
	s3.Add("Hello");
	s3.Add("world");
	s3.Add("nice");
	s3.Add("to");
	s3.Add("meet");
	s3.Add("you");

	s3.Display();

	s3.GetFront(Item3);
	s3.Retrieve3(5, Item3);
	s3.Remove();

	s3.Display();

	return 0;
}