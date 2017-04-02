//Project:	linked_list; A Linked List Implementation
//BY:		Uzair Akbar

#include<iostream>

using namespace std;

class Node
{
public:
	Node *next;
	int data;
};

class List
{
private:
	Node *ref;

public:
	List()
	{
		ref = NULL;
	}

	void Append(int a)
	{
		Node *p = ref, *q = new Node();
		q->data = a;
		q->next = NULL;

		if (p == NULL)
			ref = q;
		else
		{
			while (p->next != NULL)
			{
				p = p->next;
			}
			p->next = q;
		}
	}

	bool Delete(int a)
	{
		Node *p = ref;
		while (p->next != NULL && p->data != a)
		{
			p = p->next;
		}
		if (p->data == a && p != ref)
		{
			Node *q = ref;
			while (q->next != p)
			{
				q = q->next;
			}
			q->next = p->next;
			delete p;
			return true;
		}
		else if (p->data == a && p == ref)
		{
			ref = p->next;
			delete p;
			return true;
		}
		return false;
	}

	void Display()
	{
		Node *p = ref;

		if (p != NULL)
		{
			while (p->next != NULL)
			{
				cout << p->data;
				p = p->next;
			}
			cout << p->data << endl;
		}
	}
};

int main()
{
	List list;
	for (int i = 0; i < 10; i++)
		list.Append(i);
	list.Display();
	list.Delete(0);
	list.Delete(5);
	list.Delete(9);
	list.Delete(15);
	list.Display();

	system("PAUSE");
	return 0;
}