#include<iostream>
#include <string>
#include "GenericDoublyListP.h"
#include "GenericDoublyListP.cpp"
using namespace std;

int main()
{
	int Item;
	double Item2;
	string Item3;

	listClass<int> a1;

	a1.Insert(1, 50);
	a1.Insert(2, 60);
	a1.Insert(3, 80);
	a1.Insert(4, 40);
	a1.Insert(5, 75);
	a1.Insert(6, 45);

	a1.Display();

	a1.Insert(4, 10);
	a1.Insert(2, 30);
	a1.Insert(6, 70);

	a1.Display();
	a1.Retrieve(4, Item);

	a1.Delete(5);
	a1.Delete(2);

	a1.Display();

	a1.Delete(4);

	a1.Display();

	cout << "크기 : " << a1.Length() << endl;
	cout << endl;

	listClass<double> a2;

	a2.Insert(1, 0.5);
	a2.Insert(2, 0.6);
	a2.Insert(3, 0.8);
	a2.Insert(4, 0.4);
	a2.Insert(5, 0.75);
	a2.Insert(6, 0.45);

	a2.Display();

	a2.Insert(4, 0.1);
	a2.Insert(2, 0.3);
	a2.Insert(6, 0.7);

	a2.Display();
	a2.Retrieve(2, Item2);

	a2.Delete(5);
	a2.Delete(2);

	a2.Display();

	a2.Delete(4);

	a2.Display();

	cout << "크기 : " << a2.Length() << endl;
	cout << endl;

	listClass<string> a3;

	a3.Insert(1, "hello");
	a3.Insert(2, "world");
	a3.Insert(3, "nice");
	a3.Insert(4, "to");
	a3.Insert(5, "meet");
	a3.Insert(6, "you");

	a3.Display();

	a3.Insert(4, "i'm");
	a3.Insert(2, "fine");
	a3.Insert(6, "thankyou");

	a3.Display();
	a3.Retrieve(0, Item3);

	a3.Delete(5);
	a3.Delete(2);

	a3.Display();

	a3.Delete(4);

	a3.Display();

	cout << "크기 : " << a3.Length() << endl;
	cout << endl;

	return 0;
}