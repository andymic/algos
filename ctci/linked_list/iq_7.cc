#include<iostream>
#include"list.h"
#include<set>

//Determine if a linkedlist is a palindrome

bool isPalindrome(Node<int> *front, Node<int> *back)
{
    if(back == nullptr)
        return false;

    bool tmp = isPalindrome(front, back->next);

    if(front != back)
    {
        if(front->data == back->data)
            tmp = true;
    }

    return tmp;
}

bool isPalindrome(Node<int> *head)
{
    if(head == nullptr)
        return false;
    
    return isPalindrome(head, head);
}

int main(void)
{
    LinkedList<int> ll;

    for(int i=1; i<=15; i++)
        ll.insert(i);
    
    for(int i=14; i>=1; i--)
        ll.insert(i);
   
    ll.print();

    std::cout<<"Is palindrome: "<<isPalindrome(ll.head())<<std::endl;
    return 0;
}

