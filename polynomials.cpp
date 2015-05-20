//Project:	Polynomials
//BY:		Uzair Akbar
//GitHub:	https://github.com/uzairakbar
//Linkedin:	https://pk.linkedin.com/in/uzairakbar1
//Twitter:	https://twitter.com/uzairakbar25

#include<iostream>

using namespace std;

class Node
{
public:
	int exp;
	int coff;
	Node *next;

	Node()
	{}

	Node(int c, int e)
	{
		exp = e;
		coff = c;
		next = NULL;
	}
};

ostream& operator << (ostream& out, Node& n)
{
	if (n.coff >= 0)
		out << "+";
	out << n.coff << "^(" << n.exp << ") ";
	return out;
}

class Pol
{
private:
	Node *ref;
	int length;
	friend Pol operator + (Pol& p1, Pol& p2);

public:
	Pol()
	{
		ref = NULL;
		length = 0;
	}

	void Sort()
	{
		if (ref != NULL)
		{
			Node* current = ref;
			Node* prev = NULL;
			Node* tempNode = NULL;
			int changeFlag = 0;
			for (int i = 0; i < length; i++)
			{
				while (current->next != NULL)
				{
					tempNode = current->next;

					if (current->exp < tempNode->exp)
					{
						changeFlag = 1;
						current->next = tempNode->next;
						tempNode->next = current;
						if (prev != NULL)
							prev->next = tempNode;
						prev = tempNode;
						if (ref == current)
							ref = tempNode;
					}
					else
					{
						prev = current;
						current = current->next;
					}
				}
				if (changeFlag == 0)
					break;
				else
				{
					prev = NULL;
					current = ref;
					changeFlag = 0;
				}
			}
		}
	}

	void Insert(int coff, int exp)
	{
		Node *p = ref, *q = new Node(coff, exp);

		if (p == NULL)
		{
			ref = q;
			length++;
		}
		else
		{
			while (p->next != NULL && p->exp != q->exp)
			{
				p = p->next;
			}
			if (p->exp == q->exp)
				p->coff += q->coff;
			else
			{
				p->next = q;
				length++;
			}
		}
		
		Sort();
	}

	void Insert(Node* N)
	{
		Insert(N->coff, N->exp);
	}

	

	void Display()
	{
		Node *p = ref;
		if (p == NULL)
			cout << endl;
		else do {
			cout << *p;
			p = p->next;
		} while (p != NULL);
	}
};

Pol operator + (Pol& p1, Pol& p2)
{
	Pol P;
	Node *n1 = p1.ref, *n2 = p2.ref;
	for (int i = 0; i < p1.length; i++)
	{
		P.Insert(n1);
		n1 = n1->next;
	}
	for (int i = 0; i < p2.length; i++)
	{
		P.Insert(n2);
		n2 = n2->next;
	}
	return P;
}

int main()
{
	Pol P;
	for (int i = 0; i < 7; i++)
		P.Insert(i, 2*i);
	P.Insert(3, 3);
	P.Insert(1, 2);
	P = P + P;
	P.Display();
	system("PAUSE");
}