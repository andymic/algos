#include <iostream>
using namespace std;

struct Node{
	string key;
	Node * next;
};

class LinkedList{
private:
	Node * head = NULL;
	Node * MakeNode(string item)
	{
		Node * t =  new Node();
		t->key = item;
		t->next = NULL;
		return t;
	}
public:
    LinkedList()
	{

	}

	void Add(string item)
	{
		if(item == "") 
			return;

		Node * t = MakeNode(item);
		Node * h = head;

		if(h == NULL)
		{
			head = t;
			return;
		}

		while(h->next != NULL)
		{
			h = h->next;
		}

		h->next = t;
	}

	void Delete(string item)
	{
		if(item == "" || head == NULL)
			return;

		Node * t = head;

		if(t->key == item)
		{
			Node * d = t;
			t = t->next;
			delete d;
			return;
		}

		while(t != NULL)
		{
			if(t->next->key == item)
			{
				Node * d = t->next;
				t->next = d->next;
				delete d;
				return;
			}
			t = t->next;
		}
	}

	Node * Search(string item)
	{
		if(item == "")
			return NULL;

		Node * t = head;

		while(t != NULL)
		{
			if(t->key == item)
				return t;

			t = t->next;
		}

		return NULL;
	}
	void Print()
	{
		Node * t = head;
		if(t != NULL)
		{
			while(t != NULL)
			{
				cout<<t->key<<" ";
				t = t->next;
			}
		}
	}
};

class Hashtable{
private:
	LinkedList * array;
	int size;
	int Hash(string s)
	{
		int hash = 0;

		for(int i = 0; i<s.length(); i++)
			hash+=s[i];

		return (hash * s.length())% size;
	}
public:
	Hashtable(int _size)
	{
		array = new LinkedList[_size];
		size = _size;
	}

	void Insert(string value)
	{
		int key = Hash(value);
		array[key].Add(value);
	}

	void Delete(string value)
	{
		int key = Hash(value);
		array[key].Delete(value);
	}

	string GetKey(string value)
	{
		int key = Hash(value);

		Node * n = array[key].Search(value);

		return (n != NULL) ? n->key : "";
	}

	void PrintElements()
	{
		for(int i =0; i<size; i++)
		{
			cout<<i<<": ";
			array[i].Print();
			cout<<endl;
		}
		cout<<endl;
	}	
};
int main(void)
{
	Hashtable t(13);
	t.Insert("Andy");
	t.Insert("Michel");
	t.Insert("Joe");
	t.Insert("Jeff");
	t.Insert("Cassandra");
	t.Insert("Samuel");

	t.PrintElements();

	cout<<"Deleting: \n";
	t.Delete("Samuel");
	t.PrintElements();

	cout<<"GetItem: \n";
	cout<<t.GetKey("Andy")<<endl;

	return 0;
}
