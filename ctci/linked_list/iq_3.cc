#include<iostream>
#include "list.h"

//Delete a node in the middle of a linked list
//given access to only that node

void deleteNode_1(Node<int> *n)
{
   if(n == nullptr)
      return;
    
   Node<int> *prev;
   while(n->next != nullptr)
   {
      n->data = n->next->data;
      prev = n;
      n = n->next;     
   } 

   prev->next = nullptr;
   delete prev->next;
}

void deleteNode_2(Node<int> *n)
{
    if(n == nullptr || n->next == nullptr)
        return;    

    n->data = n->next->data;
    n->next = n->next->next;
}

int main(void)
{
    LinkedList<int> ll;
    
    for(int i=0; i<30; i++)
        ll.insert(i);
    
    ll.print();
    Node<int> *tmp = ll.find(14);
    deleteNode_2(tmp);
    ll.print();
    return 0;
}

