#include <iostream>

struct Node{
    int data;
    struct Node *next = NULL;
};

class LinkedList{
    private:
       struct Node * head;
    public:
       LinkedList();
       Node *get_head();
       void set_head(Node *phead);
       void insert(int data);
       Node* find(int data);
       void remove(int data);
       void print();
       void print_backward();
       Node * get_middle();
};
