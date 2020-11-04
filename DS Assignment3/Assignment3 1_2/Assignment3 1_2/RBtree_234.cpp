#include<iostream>
#include<string>
#define RED true
#define BLACK false
using namespace std;

typedef struct treeRecord {
	int key;
	struct treeRecord * LChild;
	struct treeRecord * RChild;
	struct treeRecord *Parent;
	bool color;
}node;

typedef node* Nptr;

class RBtree
{
	Nptr root;
	Nptr q;
public:
	RBtree()
	{
		q = NULL;
		root = NULL;
	}
	void Insert();
	void Insertfix(Nptr);
	void Leftrotate(Nptr);
	void Rightrotate(Nptr);
	void Delete();
	void disp();
	Nptr successor(Nptr);
	void delfix(Nptr);
	void Display(Nptr p);
	bool RBVerify();
};

inline void RBtree::Insert()
{
	int z, i = 0;
	cout << endl << "Enter key of the node to be inserted: ";
	cin >> z;

	Nptr p, q;
	Nptr t = new node;
	t->key = z;
	t->LChild = NULL;
	t->RChild = NULL;
	t->color = RED;
	p = root;
	q = NULL;

	if (root == NULL)
	{
		root = t;
		t->Parent = NULL;
	}
	else
	{
		while (p != NULL)
		{
			q = p;
			if (p->key < t->key)
				p = p->RChild;
			else
				p = p->LChild;
		}
		t->Parent = q;
		if (q->key < t->key)
			q->RChild = t;
		else
			q->LChild = t;
	}
	Insertfix(t);
}

inline void RBtree::Insertfix(Nptr t)
{
	Nptr u;

	if (root == t)
	{
		t->color = BLACK;
		return;
	}
	while (t->Parent != NULL && t->Parent->color == RED)
	{
		Nptr g = t->Parent->Parent;

		if (g->LChild == t->Parent)
		{
			if (g->RChild != NULL)
			{
				u = g->RChild;
				if (u->color = RED)
				{
					t->Parent->color = BLACK;
					u->color = BLACK;
					g->color = RED;
					t = g;
				}
			}
			else
			{
				if (t->Parent->RChild == t)
				{
					t = t->Parent;
					Leftrotate(t);
				}
				t->Parent->color = BLACK;
				g->color = RED;
				Rightrotate(g);
			}
		}
		else
		{
			if (g->LChild != NULL)
			{
				u = g->LChild;
				if (u->color == RED)
				{
					t->Parent->color = BLACK;
					u->color = BLACK;
					g->color = RED;
					t = g;
				}
			}
			else
			{
				if (t->Parent->LChild == t)
				{
					t = t->Parent;
					Rightrotate(t);
				}
				t->Parent->color = BLACK;
				g->color = RED;
				Leftrotate(g);
			}
		}
		root->color = BLACK;
	}
}

inline void RBtree::Delete()
{
	if (root == NULL)
	{
		cout << endl << "Empty Tree.";
		return;
	}

	int x;
	cout << endl << "Enter the key of the node to be deleted: ";
	cin >> x;

	Nptr p;
	p = root;

	Nptr y = NULL;
	Nptr q = NULL;

	int found = 0;
	while (p != NULL && found == 0)
	{
		if (p->key == x)
			found = 1;
		if (found == 0)
		{
			if (p->key < x)
				p = p->RChild;
			else
				p = p->LChild;
		}
	}
	if (found == 0)
	{
		cout << endl << "Element Not Found.";
		return;
	}
	else
	{
		cout << endl << "Deleted Element: " << p->key;
		cout << endl << "Color: ";

		if (p->color == BLACK)
			cout << "Black" << endl;
		else
			cout << "Red" << endl;

		if (p->Parent != NULL)
			cout << endl << "Parent: " << p->Parent->key;
		else
			cout << endl << "There is no parent of the node.";

		if (p->RChild != NULL)
			cout << endl << "Right Child: " << p->RChild->key;
		else
			cout << endl << "There is no right child of the node.";

		if (p->LChild != NULL)
			cout << endl << "Left Child: " << p->LChild->key;
		else
			cout << endl << "There is no left child of the node.";

		cout << endl << "Node Deleted.";

		if (p->LChild == NULL || p->RChild == NULL)
			y = p;
		else
			y = successor(p);

		if (y->LChild != NULL)
			q = y->LChild;
		else
		{
			if (y->RChild != NULL)
				q = y->RChild;
			else
				q = NULL;
		}

		if (q != NULL)
			q->Parent = y->Parent;
		if (y->Parent == NULL)
			root = q;
		else
		{
			if (y == y->Parent->LChild)
				y->Parent->LChild = q;
			else
				y->Parent->RChild = q;
		}

		if (y != p)
		{
			p->color = y->color;
			p->key = y->key;
		}

		if (y->color == BLACK)
			delfix(q);
	}
}

inline void RBtree::delfix(Nptr p)
{
	Nptr s;

	while (p != root && p->color == BLACK)
	{
		if (p->Parent->LChild == p)
		{
			s = p->Parent->RChild;

			if (s->color == RED)
			{
				s->color = BLACK;
				p->Parent->color = RED;
				Leftrotate(p->Parent);
				s = p->Parent->RChild;
			}
			if (s->RChild->color == BLACK && s->LChild->color == BLACK)
			{
				s->color = RED;
				p = p->Parent;
			}
			else
			{
				if (s->RChild->color == BLACK)
				{
					s->LChild->color == BLACK;
					s->color = RED;
					Rightrotate(s);
					s = p->Parent->RChild;
				}
				s->color = p->Parent->color;
				p->Parent->color = BLACK;
				s->RChild->color = BLACK;
				Leftrotate(p->Parent);
				p = root;
			}
		}
		else
		{
			s = p->Parent->LChild;
			if (s->color == RED)
			{
				s->color = BLACK;
				p->Parent->color = RED;
				Rightrotate(p->Parent);
				s = p->Parent->LChild;
			}
			if (s->LChild->color == BLACK && s->RChild->color == BLACK)
			{
				s->color = RED;
				p = p->Parent;
			}
			else
			{
				if (s->LChild->color == BLACK)
				{
					s->RChild->color = BLACK;
					s->color = RED;
					Leftrotate(s);
					s = p->Parent->LChild;
				}
				s->color = p->Parent->color;
				p->Parent->color = BLACK;
				s->LChild->color = BLACK;
				Rightrotate(p->Parent);
				p = root;
			}
		}
		p->color = BLACK;
		root->color = BLACK;
	}
}

inline void RBtree::Leftrotate(Nptr p)
{
	if (p->RChild == NULL)
		return;
	else
	{
		Nptr y = p->RChild;

		if (y->LChild != NULL)
		{
			p->RChild = y->LChild;
			y->LChild->Parent = p;
		}
		else
			p->RChild = NULL;

		if (p->Parent != NULL)
			y->Parent = p->Parent;
		if (p->Parent == NULL)
			root = y;
		else
		{
			if (p == p->Parent->LChild)
				p->Parent->LChild = y;
			else
				p->Parent->RChild = y;
		}
		y->LChild = p;
		p->Parent = y;
	}
}

inline void RBtree::Rightrotate(Nptr p)
{
	if (p->LChild == NULL)
		return;
	else
	{
		Nptr y = p->LChild;

		if (y->RChild != NULL)
		{
			p->LChild = y->RChild;
			y->RChild->Parent = p;
		}
		else
			p->LChild = NULL;

		if (p->Parent != NULL)
			y->Parent = p->Parent;
		if (p->Parent == NULL)
			root = y;
		else
		{
			if (p == p->Parent->LChild)
				p->Parent->LChild = y;
			else
				p->Parent->RChild = y;
		}
		y->RChild = p;
		p->Parent = y;
	}
}

inline Nptr RBtree::successor(Nptr p)
{
	Nptr y = NULL;

	if (p->LChild != NULL)
	{
		y = p->LChild;

		while (y->RChild != NULL)
			y = y->RChild;
	}
	else
	{
		y = p->RChild;

		while (y->LChild != NULL)
			y = y->LChild;
	}
	return y;
}

inline void RBtree::disp()
{
	Display(root);
}

inline void RBtree::Display(Nptr p)
{
	if (root == NULL)
	{
		cout << endl << "Empty Tree.";
		return;
	}

	if (p != NULL)
	{
		cout << endl << "NODE: ";
		cout << endl << "Key: " << p->key;
		cout << endl << "Color: ";
	}

	if (p->color == BLACK)
		cout << "Black";
	else
		cout << "Red";

	if (p->Parent != NULL)
		cout << endl << "Parent: " << p->Parent->key;
	else
		cout << endl << "There is no parent of the node";

	if (p->RChild != NULL)
		cout << endl << "Right Child: " << p->RChild->key;
	else
		cout << endl << "There is no right child of the node.";

	if (p->LChild != NULL)
		cout << endl << "Left Child: " << p->LChild->key;
	else
		cout << endl << "There is no left child of the node.";
	cout << endl;

	if (p->LChild)
	{
		cout << endl << endl << "Left: ";
		Display(p->LChild);
	}
	if (p->RChild)
	{
		cout << endl << endl << "Right: ";
		Display(p->RChild);
	}
}

inline bool RBtree::RBVerify() {
	return true;
}