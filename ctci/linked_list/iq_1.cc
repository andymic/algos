#include<iostream>
#include "list.h"

void removedups(LinkedList<int> &ll)
{
    
    Node<int> *curr = ll.head();   
    Node<int> *runner;
    
    while(curr != nullptr)
    {
        int cnt = 0;
        runner = ll.head();
        while(runner != nullptr)
        {
            if(runner->data == curr->data)
            {
                cnt++;
            }

            if(cnt > 1)
            {
                ll.remove(runner->data);
                cnt--;
            }
            runner = runner->next;
        }
       curr = curr->next; 
    }
}

int main(void)
{
    LinkedList<int> ll;
    
    for(int i=0; i<10; i++)
        ll.insert(i);
    
    for(int i=0; i<10; i++)
        ll.insert(i);
    
    ll.print();
    removedups(ll);
    ll.print();
    return 0;
}

