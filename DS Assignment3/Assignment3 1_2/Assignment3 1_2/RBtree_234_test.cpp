#include<iostream>
#include "RBtree_234.cpp"
using namespace std;

int main()
{
	int ch, y = 0;
	RBtree obj;

	do
	{
		cout << endl << "RED BLACK TREE";
		cout << endl << "1. Insert";
		cout << endl << "2. Delete";

		cout << endl << "3. Display";
		cout << endl << "4. RBVerify";
		cout << endl << "5. Exit";
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
		case 4: {
			int x = obj.RBVerify();
			if (x == 1) cout << "True" << endl;
			else cout << "False" << endl;
			break;
		}
		case 5: y = 1;
			break;
		default: cout << endl << "Enter a Valid Choice.";
		}
		cout << endl;
	} while (y != 1);

	return 1;
}