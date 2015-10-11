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

Node * Search(Node * root, int data)
{
	if(root == NULL)
		return NULL;

	if(root->data == data)
		return root;
	else if(data > root->data)
	    Search(root->right, data);
	else
		Search(root->left, data);
}

Node * FindMin(Node * root)
{
	if(root == NULL)
		return NULL;

	while(root->left != NULL)
		root = root->left;

	return root;
}

Node * FindMax(Node * root)
{
	if(root == NULL)
		return NULL;

	while(root->right != NULL)
		root = root->right;

	return root;
}

bool IsLeaf(Node * n)
{
	return (n->left == NULL && n->right == NULL) ? true : false;
}

bool HasRightChild(Node * n)
{
	return (n->right != NULL) ? true : false;
}

bool HasLeftChild(Node * n)
{
	return (n->left != NULL) ? true : false;
}

Node * Delete(Node * root, int data)
{ 
	/**
	Case:
		1-No children or leaf node...remove link from parent and reclaim memory
		2-One child...connect the parent to the only child then delete node object from memory
		3-Two children
			a)Get minimun in right, copy it to the node to delete then remove duplicate
			b)Get maximun from the left subtree copy to target node then delete duplicate
	**/
	if(root == NULL)
		return NULL;
	else if(data < root->data)
		root->left = Delete(root->left, data);
	else if(data > root->data)
		root->right = Delete(root->right, data);
	else
	{
		if(IsLeaf(root))
		{
			delete root;
			root = NULL;
		}
		else if(!HasLeftChild(root))
		{
			Node * temp = root;
			root =  root->right;
			delete temp;
		}
		else if(!HasRightChild(root))
		{
			Node * temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			Node * temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
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

Node * GetSuccessorNode(Node * root, int data, Node * parent)
{
	if(root == NULL)
		return NULL;

	if(data == root->data)
	{
		if(root->right != NULL)
		{
			if(root->right->left != NULL)
			{
				root = root->right;

				while(root->left != NULL)
					root = root->left;

				return root;
			}
			else
			return root->right;
		}
		else
			return parent;
	}
	else if(data < root->data)
	{
		GetSuccessorNode(root->left, data, parent = root);
	}
	else
		GetSuccessorNode(root->right, data, parent = root);
}

Node * LeastCommonAncesstorBST(Node * root, Node * a, Node * b)
{
	if(root == NULL || a == NULL || b == NULL)
		return NULL;

	if(max(a->data, b->data) < root->data)
		LeastCommonAncesstorBST(root->left, a, b);
	else if(min(a->data, b->data) > root->data)
		LeastCommonAncesstorBST(root->right, a, b);
	else
		return root;
}

Node * LeastCommonAncesstorBT(Node * root, Node * a, Node * b)
{
	return NULL;
}

Node * FindKthSmallest(Node * root, int * k)
{
	if(root == NULL)
		return NULL;
	else
	{

		Node * temp = FindKthSmallest(root->left, k);

		if(temp)
			return temp;

		(*k)--;

		if(*k == 0)
			return root;

	    return FindKthSmallest(root->right, k);
	}
}

Node * FindKthLargest(Node * root, int * k)
{
	if(root == NULL)
		return NULL;

	Node * temp = FindKthLargest(root->right, k);

	if(temp)
		return temp;

	(*k)--;

	if(*k == 0)
		return root;

	return FindKthLargest(root->left, k);
}

bool IsSubtreeMatch(Node * a, Node * b)
{
	if(a == NULL && b == NULL)
		return true;
	
	if(a == NULL || b == NULL)
		return false;

	return(a->data == b->data && 
		IsSubtreeMatch(a->left, b->left) &&
		IsSubtreeMatch(a->right, b->right));
}

bool IsSubtree(Node * a, Node * b)
{
	if(a == NULL)
		return false;

	if(b == NULL) 
		return true;

	if(IsSubtreeMatch(a, b))
		return true;

	//check left or right subtrees if current node is not a match
	return IsSubtree(a->left, b) || IsSubtree(a->right, b); 
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

void FindKthLargestTest()
{
	int tree[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	//int tree[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

	Node * root = NULL;

	root = CreateMinimalHeightBTree(tree, 0, 15);

	LevelOrderPrettyPrint(root);

	int p = 10;

	Node * temp = FindKthLargest(root, &p);

	if(temp != NULL)
		cout<<temp->data<<endl;
}


int main(void)
{
	
	//int tree[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int treeb[7] = {21,4,32,2,15,3,15};
	int tree[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

	Node * root = NULL;
	Node * rootb = NULL;

	for(int i = 0; i<16; i++)
		root = Insert(root, tree[i]);

	for(int i = 0; i<7; i++)
		rootb = Insert(rootb, treeb[i]);
	//root = CreateMinimalHeightBTree(tree, 0, 15);
	//rootb = CreateMinimalHeightBTree(treeb, 0, 3);
	cout<<"Tree 1:\n";
	LevelOrderPrettyPrint(root);
	cout<<"Tree 2:\n";
	LevelOrderPrettyPrint(rootb);

	cout<<IsSubtree(root, rootb);

	return 0;
}