#include <iostream>

using namespace std;

struct Node {
	int data;
	Node * left;
	Node * right;
};

class BinaryTree{
private:
	Node * root = NULL;
public:
	Node * GetRoot()
	{
		return root;
	}

	void AddNode(Node * node, int data)
	{
		if(node == NULL)
		{
			Node * n = new Node();
			node->left = NULL;
			node->right = NULL;
			node->data = data;

			root = n;
		}
		else
		{
			if(root->data < data)
				AddNode(node->right, data);
			else
				AddNode(node->left, data);
		}
	}

	void DeleteNode(Node * node, int data)
	{
		
	}

	Node * Search(Node * node, int target)
	{
		if(node == NULL)
			return NULL;

		if(node->data == target)
			return node;

		if(node->data < target)
			Search(node->right, target);
		else
			Search(node->left, target);
	}

};
int main(void)
{
	return 0;
}