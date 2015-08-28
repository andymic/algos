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

	Node * Gethead()
	{
		return head;
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
				delete head;
				return true;
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

	void RemoveDuplicates()
	{
		if(head == NULL)
			return;

		Node * t_curr = head;
		Node * t_runner =  new Node();
		Node * t_runner_prev = new Node();

		while(t_curr != NULL)
		{
			t_runner = head;

			while(t_runner != NULL)
			{
				if(t_runner != t_curr && t_runner->data == t_curr->data)
				{
					t_runner_prev->next = t_runner->next;
					delete t_runner;
					t_runner = t_runner_prev;
				}

				t_runner_prev = t_runner;
				t_runner = t_runner->next;
			}
			t_curr = t_curr->next;
		}
	}

	int KthToLast(int n)
	{
		if(head == NULL)
			return -1;

		Node * t_head = head;
		int count = 0;
		while(t_head != NULL)
		{
			count++;
			t_head = t_head->next;
		}

		t_head = head;

		if(n > count)
			return -1;

		for(unsigned int i =0; i< count-n; i++)
		{
			t_head = t_head->next;
		}

		return t_head->data;
	}

	Node * KthToLast(Node * n_head, int n, int& i)
	{
		if(n_head == NULL)
			return NULL;

	    Node * rec = KthToLast(n_head->next, n, i);
		i++;

		if(i == n)
			return n_head;

		return rec;
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
	int k = 0;
	 list->Add(0);
	 list->Add(1);
	 list->Add(2);
	 list->Add(3);
	 list->Add(3);
	 list->Add(5);
	 list->Add(1);
	 list->Print();
	 cout<<list->KthToLast(list->Gethead(),4, k)->data;
	 //list->Print();

	return 0;
}