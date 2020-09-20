#include<iostream>
#include"list.h"
#include<vector>
#include<algorithm>
#include<random>

//Partition list around x such that values
//that are less than x come before x and values
//that are equal or more appear after

void partition(LinkedList<int> &ll, int val)
{
    std::vector<int> before, after;

    Node<int> *curr = ll.head();

    while(curr != nullptr)
    {
        if(curr->data != val)
        {
            if(curr->data < val)
            {
                before.push_back(curr->data);
            }
            else
            {
                after.push_back(curr->data);
            }
        }
        curr = curr->next;
    }

    LinkedList<int> tmp;

    for(int i : before)
        tmp.insert(i);

    tmp.insert(val);

    for(int i : after)
        tmp.insert(i);

    ll = tmp;
}

int main(void)
{
    LinkedList<int> ll;
    std::vector<int> vec;

    for(int i=0; i<30; i++)
         vec.push_back(i);
    
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(vec.begin(), vec.end(), g);

    for(int i : vec)
        ll.insert(i);
    
    ll.print();
    partition(ll, 13);
    ll.print();
    return 0;
}

