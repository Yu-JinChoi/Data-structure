#include<iostream>
#include "DoublyListP.h"
using namespace std;

int main()
{
	int item=0;

	listClass list;
	list.Insert(1, 50);
	list.Insert(2, 60);
	list.Insert(3, 80);
	list.Insert(4, 40);
	list.Insert(5, 75);
	list.Insert(6, 45);

	list.Display();

	list.Insert(4, 10);
	list.Insert(2, 30);
	list.Insert(6, 70);

	list.Display();
	list.Retrieve(3, item);
	cout << endl;

	list.Delete(5);
	list.Delete(2);

	list.Display();
	list.Retrieve(0, item);
	cout << endl;

	list.Delete(4);

	list.Display();

	cout << "Å©±â : " << list.Length() << endl;

	return 0;
}