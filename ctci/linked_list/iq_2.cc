#include<iostream>
#include "list.h"

//Find Kth to last element of a singly linked list
Node<int>* findKthRec(int k, int &c, Node<int> *n)
{
    if(n == nullptr)
        return nullptr;

    Node<int> *tmp = findKthRec(k, c, n->next);

    c++;

    if(k == c)
        return n;

    return tmp;
}

Node<int>* findKthRec(int k, Node<int> *n)
{
    int c = 0;
    return findKthRec(k,c,n);
}

Node<int>* findKthIter(int k, Node<int> *n)
{
    if(n == nullptr)
        return nullptr;

    Node<int> *target, *end;
    target = end = n;

    for(int i=0; i<k; i++)
    {
        if(end == nullptr)
           return nullptr; 
        end = end->next;
    }

    if(end == nullptr)
        return nullptr;

    while(end != nullptr)
    {
        end = end->next;
        target = target->next;
    }
    return target;
}

int main(void)
{
    LinkedList<int> ll;
    
    for(int i=0; i<30; i++)
        ll.insert(i);
    
    ll.print();

    std::cout<<findKthIter(8, ll.head())->data<<std::endl;
    return 0;
}

