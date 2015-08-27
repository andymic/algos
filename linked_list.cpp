#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node * next;
};

class Linked_list
{
private:
	Node * head = NULL;
public:
	Linked_list()
	{
		//head = NULL;
	}

	void Add(int data)
	{
		if(head == NULL)
		{
			Node * n = new Node();
			n->data = data;
			n->next = NULL;

			head = n;
			return;
		}

		Node * t = head;
		Node * n = new Node();
		n->next = NULL;
		n->data = data;

		while(t->next != NULL)
		{
			t = t->next;
		}

		t->next = n;
	}

	bool Delete(int data)
	{
		if(head==NULL)
			return false;

		Node * n = head;	

		if(head->data == data)
		{
			if(head->next == NULL)
			{
				cout<<"List contains only one element";
				delete head;
				return NULL;
			}

			Node * temp = new Node();
			temp = head->next;

			head->data = temp->data;

			head->next = temp->next;

			delete temp;
		}

		Node * t = new Node();
		while(n != NULL)
		{
			if(n->data == data)
			{
				t->next = n->next;
				delete n;
				n = t;
			}

			t = n;
			n = n->next;
		}

		return true;
	}

	void Print()
	{
		if(head == NULL)
		{
			cout<<"List is empty"<<endl;
		}

		Node * t = head;
		while(t != NULL)
		{
			cout<<t->data;
			t=t->next;
		}
		cout<<endl;	
	}

	~Linked_list();
	
};
int main(void)
{
	Linked_list * list = new Linked_list();

	 list->Add(0);
	 list->Add(1);
	 list->Print();
	 list->Delete(9);
	 list->Print();

	return 0;
}