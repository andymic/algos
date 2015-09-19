#include <iostream>
#include <cmath>
using namespace std;

struct Node {
	int data;
	Node * left;
	Node * right;
};

Node * makeNode(int data)
{
	Node * n = new Node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

Node * Insert(Node * root, int data)
{
	if(root == NULL)
	{
		root = makeNode(data);
	}
	else if(data > root->data)
		root->right = Insert(root->right, data);
	else
		root->left = Insert(root->left, data);

	return root;
}

void InOrderPrint(Node * root)
{
	if(root != NULL)
	{
		InOrderPrint(root->left);
		cout<<root->data<<" ";
		InOrderPrint(root->right);
	}
	else
	{
		return;
	}
}

void PreOrderPrint(Node * root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		PreOrderPrint(root->left);
		PreOrderPrint(root->right);
	}
	else
	{
		return;
	}
}

void PostOrderPrint(Node * root)
{
	if(root != NULL)

	{
		PostOrderPrint(root->left);
		PostOrderPrint(root->right);
		cout<<root->data<<" ";
	}
	else
	{
		return;
	}
}

bool IsBalanced(Node * root)
{
	Node * left = root;
	Node * right = root;

	int leftHeight = 0;
	int rightHeihgt = 0;

	cout<<"Left data : ";
	while(left != NULL)
	{
		cout<<left->data<< " ";
		if(left->left != NULL)
			left = left->left;
		else 
			left = left->right;

		leftHeight++;

		
	}
	cout<<endl;
	cout<<"Right data : ";
	while(right != NULL)
	{
		cout<<right->data<< " ";
		if(right->right != NULL)
			right = right->right;
		else 
			right = right->left;
		
		rightHeihgt++;
	}
	cout<<endl;
	cout<<"Left "<<leftHeight<<" Right "<<rightHeihgt<<endl;
	return (abs(left - right) < 2);
}
int main(void)
{
    const int tree[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
	Node * root = NULL;

	for(int i=0; i<16; i++)
	 root = Insert(root, tree[i]);

	PreOrderPrint(root);
	cout<<endl;
	cout<<IsBalanced(root)<<endl;
	cout<<endl;
	return 0;
}