#include <iostream>
#include <cmath>
#include <queue>
#include <list>
#include <limits.h>

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
	queue<Node*> level;

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

void LevelOrderPrettyPrint(Node * root)
{
	if(root == NULL)
		return;

	queue<Node*> currlevel;
	int nodesInCurrLevel = 1, nodesInNextLevel = 0;

	currlevel.push(root);

	while(!currlevel.empty())
	{
		Node * temp = currlevel.front();
		currlevel.pop();
		nodesInCurrLevel--;

		if(temp)
		{
			cout<<temp->data<<" ";
			currlevel.push(temp->left);
			currlevel.push(temp->right);
			nodesInNextLevel+=2;
		}

		if(nodesInCurrLevel == 0)
		{
			nodesInCurrLevel = nodesInNextLevel;
			nodesInNextLevel = 0;
			cout<<endl;
		}
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

list<int> * CreateListByLevel(Node * root)
{
	//Returns pointer to an array D list(s) where D is the depth of the tree
	if(root == NULL)
		return NULL;

	int depth = TreeHeight(root);

	queue<Node*> currlevel;
	currlevel.push(root);

	list<int> * arList = new list<int>[depth];
	list<int> tempList;

	int nodesInCurrLevel = 1, nodesInNextLevel = 0;
	int index = 0;

	while(!currlevel.empty())
	{
		Node * curr = currlevel.front();
		currlevel.pop();
		nodesInCurrLevel--;

		if(curr)
		{
			tempList.push_back(curr->data);
			currlevel.push(curr->left);
			currlevel.push(curr->right);
			nodesInNextLevel += 2;
		}

		if(nodesInCurrLevel == 0)
		{
			nodesInCurrLevel = nodesInNextLevel;
			nodesInNextLevel = 0;

			if(index < depth)
			{
				arList[index] = tempList;
				index++;
				tempList.clear();
			}
		}
	}

	return arList;
}

bool IsBSTHelper(Node * root, int min, int max)
{
	if(root == NULL)
		return true;

	if(root->data > min && root->data <= max 
		&& IsBSTHelper(root->left, min, root->data)
		&& IsBSTHelper(root->right, root->data, max))
		return true;
	else
		return false;
}

void IsBSTHelper(Node * root, list<int> * n)
{
	if(root == NULL)
		return;

	IsBSTHelper(root->left, n);
	n->push_back(root->data);
	IsBSTHelper(root->right, n);
}

bool IsBST(Node * root)
{
	if(root == NULL)
		return true;

	return IsBSTHelper(root, INT_MIN, INT_MAX);
}

bool IsBSTL(Node * root)
{
	if(root == NULL)
		return true;

	//check if tree is BST using a list
	list<int> * n = new list<int>;
	IsBSTHelper(root, n);

	list<int>::iterator it;

	int prev = INT_MIN;

	for(it = n->begin(); it!= n->end(); it++)
	{
		if(*it < prev)
			return false;
		else
			prev = *it;
	}

	return true;
}


/////////////////////////////////////////////////////////////////////Test Methods/////////////////////////////////////////////////////////
void CreateListByLevelTest()
{
	int tree[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	Node * root = NULL;

	root = CreateMinimalHeightBTree(tree, 0, 15);

	list<int> * arList = CreateListByLevel(root);
	int depth = TreeHeight(root);

	for(int i =0; i<depth; i++)
	{
		cout<<"List "<<i+1<<endl;
		for(list<int>::iterator it = arList[i].begin(); it!= arList[i].end(); it++ )
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}

	delete [] arList;
}

int main(void)
{
	//int tree[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	//int tree[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

	Node * root = NULL;

	root = CreateMinimalHeightBTree(tree, 0, 15);

	LevelOrderPrettyPrint(root);

	cout<<IsBSTL(root);

	return 0;
}