#include <iostream>
#include <cmath>
#include <queue>

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

void LevelOrderPrint(Node * root)
{
	//using a queue
	if(root == NULL)
		return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		Node * front = q.front();
		cout<<front->data<<endl;

		if(front->left != NULL)
			q.push(front->left);

		if(front->right != NULL)
			q.push(front->right);

		q.pop();
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

Node * CreateMinimalHeightBTree(Node * root, const int tree [], int len)
{
	//iterative ,m 
	if(len == 0)
		return NULL;

	int midelem = len/2;

	root = Insert(root, tree[midelem]);

	for(int i = 0; i<=len; i++)
	{
		if(i != midelem)
			root = Insert(root, tree[i]);
	}

	return root;
}

Node * CreateMinimalHeightBTree(int tree [], int start, int end)
{
	//recursive...faster by cutting the extra traversal down tree.
	if(end < start)
		return NULL;

	int mid = (start+end)/2;
	Node * n = makeNode(tree[mid]);
	n->left = CreateMinimalHeightBTree(tree, start, mid -1);
	n->right = CreateMinimalHeightBTree(tree, mid+1, end);

	return n;
}

int main(void)
{
    //const int tree[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

    //int tree[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	int tree[5] = {0,1,2,3,4};
	Node * root = NULL;

	root = CreateMinimalHeightBTree(tree, 0, 4);

	// for(int i=0; i<16; i++)
	//  root = 
	//InOrderPrint(root);
	LevelOrderPrint(root);

	root = NULL;
	cout<<endl;
	root = CreateMinimalHeightBTree(root, tree, 4);
	LevelOrderPrint(root);

	return 0;
}