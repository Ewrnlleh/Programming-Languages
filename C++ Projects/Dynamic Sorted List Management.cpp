
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct List
{
	Node* head;
	Node* last;
	List() { head = NULL; last = NULL; }

	void add(Node* e)
	{
		if (head == NULL)
			head = e;
		else
			last->next = e;
		last = e;
	}

	void addAndSort(Node* e) {
		Node* p = head;
		Node* p2 = last;
		Node* old = NULL;
		if (p == p2)
		{
			if (p->data > e->data)
			{
				e->next = p;
				head = e;
			}
			else
			{
				p->next = e;
				last = e;
			}
		}
		else
		{
			int counter = 0;
			bool ctrl = false;
			while (p != NULL)
			{
				if (p->data > e->data)
				{
					if (counter == 0)
					{
						e->next = p;
						head = e;
						ctrl = true;
					}
					else
					{
						old->next = e;
						e->next = p;
						ctrl = true;
					}
					break;
				}

				if (p != p2)
				{
					old = p;
					p = p->next;
					ctrl = false;
				}
				else
				{
					ctrl = false;
					p->next = e;
					last = e;
					p = NULL;
				}
				counter++;
			}
		}
	}

	void allNodes()
	{
		Node* p = head;
		Node* p2 = last;
		while (p != NULL)
		{
			cout << p->data << "\n";
			if (p != p2)
				p = p->next;
			else
				p = NULL;
		}
		cout << endl;
	}

};


int main() {
	int x;
	List li;

	for (int i = 0; i < 10; i++)
	{
		cout << "sayi girin" << endl;
		cin >> x;
		Node* e = new Node;
		e->data = x;
		if (i > 0)
			li.addAndSort(e);
		else
			li.add(e);

	}
	cout << "Siralanmis liste" << endl;
	li.allNodes();

	return 0;
}
