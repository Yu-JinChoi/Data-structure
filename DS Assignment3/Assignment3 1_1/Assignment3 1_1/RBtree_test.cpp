#include<iostream>
#include "RBtree.cpp"
using namespace std;

int main()
{
	int ch, y = 0;
	RBtree obj;

	do
	{
		cout << endl << "RED BLACK TREE";
		cout << endl << "1. Insert in the tree ";
		cout << endl << "2. Delete a node from the tree ";

		cout << endl << "3. Display the tree ";
		cout << endl << "4. Exit";
		cout << endl << "Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1: obj.Insert();
			cout << endl << "Node Inserted." << endl;
			break;
		case 2: obj.Delete();
			break;
		case 3: obj.disp();
			break;
		case 4: y = 1;
			break;
		default: cout << endl << "Enter a Valid Choice.";
		}
		cout << endl;
	} while (y != 1);

	return 1;
}