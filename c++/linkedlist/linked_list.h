#include <iostream>
#include <string.h>
#include <sstream>
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

	int GetLen()
	{
		Node * t = head;
		int count = 0;
		while(t != NULL)
		{
			count++;
			t=t->next;
		}
		return count;
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

	void AddNode(Node * n)
	{
		if(n == NULL)
			return;

		if(head == NULL)
		{
			head = n;
			return;
		}

		Node * t = head;

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

	Node * Partition(int x)
	{
		if(head == NULL)
			return NULL; 

		Node * left = new Node();
		Node * left_head = left;
		Node * right = new Node();
		Node * right_elements = right;
		Node * right_head = new Node();
		Node * t_head = head;
		bool right_head_set = false;

		while(t_head != NULL)
		{
			if(t_head->data < x)
			{
				left->next = t_head;
				left = left->next;
			}
			else if(t_head->data == x && right_head_set)
			{
				left->next = t_head;
				left = left->next;
			}
			else if((t_head->data == x) && (!right_head_set))
			{
				right_head = t_head;
				right_head_set = true;
			}
			else
			{
				right->next =  t_head;
				right = right->next;
			}
			t_head = t_head->next;
		}

		right->next = NULL;
		right_head->next = right_elements->next;
		 

		if(left != NULL)
		{
			left->next = right_head;
			return left_head->next;
		}


	}

	string AddLinkedList(Node * a, Node * b, string& v, int& carry)
	{
		//assuming list are the same size if not then easy tweak
		if(a == NULL && b == NULL)
			return "";

		int ops = a->data + b->data + carry;

		 std::stringstream out;

		 if(ops > 9)
		 {
		 	out << ops % 10;
		 	carry = ops / 10;
		 	v += out.str();
		 }
		 else
		 {
		 	carry = 0;
		 	out<<ops;
		 	v += out.str();
		 }

		AddLinkedList(a->next, b->next, v, carry);

		return v;
	}

	Node * GetCircleHead(Linked_list * list)

	{
		if(list == NULL)
			return NULL;

		Node * current = list->Gethead();
		Node * runner = list->Gethead();

		if(current->next == NULL)
			return NULL;

		while(current != NULL)
		{
			current = current->next;
			runner = runner->next->next;

			if(runner == NULL)
				return NULL; //not circular

			if(current == runner || current == runner->next)
				return current;

		}

		return NULL;
	}

	bool IsPalindrome(Node * n, int& len, int& counter)
	{
		if(n == NULL)
			return false;

		Node * a = n;
		Node * b = n;

		IsPalindrome(b->next, len, counter);

		if(counter<len/2)
		{
			counter++;
			if(a->data != b->data)
				return false;

			a = a->next;
		}
		

		return true;
	}
	void Print()
	{
		if(head == NULL)
		{
			cout<<"List is empty"<<endl;
			return;
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
// int main(void)
// {
// 	Linked_list * list = new Linked_list();


// 	list->Add(7);
// 	list->Add(1);
// 	list->Add(6);
// 	list->Add(3);
// 	list->Add(2);
// 	list->Add(17);
// 	list->Add(15);
// 	list->Add(78);
// 	list->Add(34);
// 	list->Add(65);

// 	Node * temp = list->Partition(17);

// 	while(temp != NULL)
// 	{
// 		cout<<temp->data;
// 		temp = temp->next;
// 	}
// 	cout<<endl;
// 	return 0;
// }