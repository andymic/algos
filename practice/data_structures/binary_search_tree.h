#include <iostream>

struct BNode{
    int data;
    BNode *left = NULL;
    BNode *right = NULL;
};

class BinarySearchTree {
    private:
        BNode *head = NULL;
        int height;
    public:
        BinarySearchTree();
        BNode* get_root();
        BNode* insert(BNode *root, int data);
        BNode* remove(BNode *root, int data);
        BNode* search(BNode *root, int data);
        void print();
};
