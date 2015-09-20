#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

struct Node{
	int data;
	Node * next;
};

Node * Insert(Node * head, int data)
{
	Node * temp = new Node();
	temp->data = data;
	temp->next = NULL;

	if(head==NULL)
	{
		return temp;
	}

	Node * temp1=head;
	while(temp1->next != NULL)
	{
		temp1  = temp1->next;
	}

	temp1->next=temp;

	return head;
}

void Print(Node* head)
{
	while(head != NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}

Node * findKth( Node * head, int k)
{
	Node * temp = head;
	int count=0; 
	Node * temp1 = head;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}

	for(int i=0; i<count-k; i++)
		temp1 = temp1->next;

	return temp1;
}

void DeleteGivenNode(Node * n)
{
	if(n==NULL || n->next ==NULL)
		return;
	Node * temp;

	temp = n->next;
	n->data = temp->data;
	n->next = temp->next;
}

Node * PartitionNode(Node * head, int val)
{
	Node * first=NULL;
	Node * second=NULL;
	Node * n = head;
	Node * mid = NULL;

	while(n!=NULL)
	{
		if(n->data < val)
		{
			first = Insert(first, n->data);
		}
		else if(n->data==val)
		{
			mid = Insert(mid, n->data);
		}
		else
		{
			second = Insert(second, n->data);
		}
		n = n->next;
	}

	first = Insert(first, mid->data);

	cout<<"first: "<<endl;
	Print(first);
	cout<<"second: "<<endl;
	Print(second);

	Node * res= first;
	while(first->next != NULL)
	{
		first=first->next;
	}
	 first->next = second;

	 return res;
} 

Node * AddListInReverse(Node * A, Node * B)
{
	string a=""; 
	string b="";

	stringstream sa;
	stringstream sb;

	while(A!=NULL)
	{
		sa<< A->data;
		A=A->next;
	}

	a=sa.str();

	while(B!=NULL)
	{
		sb<< B->data;
		B=B->next;
	}
	b=sb.str();

	int len_a=a.length();

	for(int i=0, e=len_a; i<len_a/2; i++, e--)
	{
		char temp = a[i];
		a[i] = a[e];
		a[e]=temp;
	}

	int len_b=b.length();

	for(int i=0, e=len_b; i<len_b/2; i++, e--)
	{
		char temp = b[i];
		b[i] = b[e];
		b[e]=temp;
	}

	int _a= atoi(a.c_str());
	int _b= atoi(b.c_str());
	std::ostringstream ss;
	int res = _a+_b;


	ss<<res;

	string _res = ss.str();

	Node * result = NULL;

	for(int i=_res.length(); i>0; i--)
	{
		result = Insert(result, _res[i]);
	}

	return result;
}

Node * AddLInReverse(Node * A, Node * B, int carry)
{
	if(A==NULL && B==NULL && carry==0)
		return NULL;

	int val=carry;

	if(A!=NULL)
		val+=A->data;

	if(B!=NULL)
		val+=B->data;

	cout<<"Value of a+b : "<<val<<endl;
	Node * result = new Node();
	result->data = val % 10;

	if(A!=NULL || B!=NULL){
		Node * temp = AddLInReverse(A==NULL ? NULL : A->next,
									B==NULL ? NULL : B->next,
									(val>10) ? 1 : 0);

	result->next = temp;
}
	return result;
}

Node * Reverse(Node * head)
{
	if(head==NULL)
		return NULL;

	Node * current, * prev, * next;
	prev = NULL;
	current = head;

	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

Node * ReverseRec(Node * current, Node * prev, Node * next)
{
	cout<<"ReverseRec"<<endl;
	if(current==NULL)
		return prev;

	next = current->next;
	current->next = prev;
	prev = current;
	current = next;

	ReverseRec(current,prev,next);
}

void PrintForward(Node * head)
{
	if(head==NULL)
		return;

	cout<<head->data;
	PrintForward(head->next);
}

void PrintBackward(Node * head)
{
	if(head==NULL)
		return;

	PrintBackward(head->next);

	cout<<head->data;
}

Node * ReturnNodeStart(Node * head)
{
	Node * slow, * fast;
	slow = head;
	fast = slow;

	if(head==NULL)
		return NULL;

	while(true)
	{
		slow = slow->next;

		if(slow==NULL)
			return NULL;

		if(fast->next != NULL)
			fast = fast->next->next;

		if(slow==fast)
			return slow;

		if(fast==NULL)
			return NULL;
	}
}

int ListLength(Node * head)
{
	int count =0; 
	while(head !=NULL)
	{
		count++;
		head = head->next;
	}

	return count;
}
// bool IsPalindrome(Node * head)
// {

// 	int len = ListLength(head);

// 	cout<<"List length: "<<len<<endl;
// 	Node * temp = head;
// 	Node * start = head;

// 	cout<<"head befoore Reverse"<<endl;
// 	Print(head);

// 	Node * rev = Reverse(temp);

// 	cout<<"Reversed"<<endl;
// 	Print(rev);
	

// 	cout<<"start"<<endl;
// 	Print(start);

// 	for(int i=0; i<len/2; i++)
// 	{
// 		if(rev->data != start->data)
// 			return false;

// 		rev= rev->next;
// 		start= start->next;
// 		cout<<"true"<<endl;
// 	}

// 	return true;
// }

bool IsPalindromeStack(Node * head)
{
	Node * slow, * fast;
	slow = head;
	fast = head;

	stack<int> nodes;

	while(fast != NULL && fast->next != NULL)
	{
		nodes.push(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}

	if(fast!=NULL)
		slow = slow->next;

	while(slow != NULL)
	{
		int data = nodes.top();

		nodes.pop();
		if(data != slow->data)
			return false;
		else
			slow = slow->next;
	}

	return true;
}

int main(void)
{
	Node * A = NULL;
	Node * B = NULL;

	for (int i = 0; i<10; i++)
	{
		A = Insert(A, i);
		if(i==5)
			break;
	}
	for (int i = 4; i>=0; i--)
	{
		A = Insert(A, i);
	}
	Print(A);
	cout<<endl;
	cout<<IsPalindromeStack(A);
	//Print(Reverse(A));
	

	return 0;
}