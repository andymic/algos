#include<iostream>
#include "list.h"

//Find Kth to last element of a singly linked list
Node<int>* findKth(int k, int &c, Node<int>* n)
{
    if(n == nullptr)
        return nullptr;

    Node<int> *tmp = findKth(k, c, n->next);

    c++;

    if(k == c)
        return n;

    return tmp;
}

Node<int>* findKth(int k, Node<int>* n)
{
    int c = 0;
    return findKth(k,c,n);
}

int main(void)
{
    LinkedList<int> ll;
    
    for(int i=0; i<30; i++)
        ll.insert(i);
    
    ll.print();

    std::cout<<findKth(8, ll.head())->data<<std::endl;
    return 0;
}

