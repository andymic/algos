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

int Max(int a, int b)
{
	return (a >= b) ? a : b;
}

int TreeHeight(Node * node)
{
	if(node == NULL)
		return 0;

	return 1+Max(TreeHeight(node->left), TreeHeight(node->right));
}

bool IsBalanced(Node * root)
{
	if(root == NULL)
		return false;

	int lh = 0, rh = 0;

	lh = TreeHeight(root->left);
	rh = TreeHeight(root->right);

	cout<<"Left "<<lh<<" Right "<<rh<<endl;
	return abs(lh - rh) <= 1;
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