#include<iostream>
#include"list.h"
#include<set>
//Write an algorithm that return the node
//at the begining of a loop

Node<int>* detectLoop(Node<int>* head)
{
    Node<int> *curr=head;

    if(curr == nullptr)
        return nullptr;

    std::set<Node<int>*> tmp;

    while(curr->next != nullptr)
    {
        if(tmp.insert(curr).second == false)
            return curr;

        curr = curr->next;
    }

    return nullptr;
}

int main(void)
{
    LinkedList<int> ll;

    for(int i=1; i<=30; i++)
        ll.insert(i);
    
    ll.insert(ll.find(15));
   
    std::cout<<"Loop head: "<<detectLoop(ll.head())->data<<std::endl; 
    return 0;
}

