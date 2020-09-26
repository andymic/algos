#include<iostream>
#include"list.h"
#include<vector>
#include<algorithm>
#include<random>

//Add two linkedlist where their numbers are 
//stored in reverse (7->1->6) + (5->9->2) = 2->1->9
//                    617         295           912

void addBackwards(Node<int> *nt, Node<int> *nb, LinkedList<int> &res, int &carry)
{
    if(nt == nullptr || nb == nullptr)
    {
        if(carry > 0)
            res.insert(carry);
        return;
    }

    int val = nt->data + nb->data + carry;

    if(val > 9)
    {
        carry = val % 10;
        res.insert(carry);
        carry = 1;
    }
    else
    {
        res.insert(val);
        carry = 0;
    }

    addBackwards(nt->next, nb->next, res, carry);
}


void addForward(Node<int> *nt, Node<int> *nb, LinkedList<int> &res, int &carry, int &step, std::vector<int> &tmp)
{
    if(nt == nullptr || nb == nullptr)
    {
        return;
    }
  
   step++; 
   addForward(nt->next,nb->next,res,carry,step,tmp);

    
    int val = nt->data + nb->data + carry;
    
    if(val > 9)
    {
        carry = val % 10;
        tmp.push_back(carry);
        carry = 1;
    }
    else
    {
        tmp.push_back(val);
        carry = 0;
    }
    
    step--;

    if(step == 0) 
    {
        if(carry > 0)
            tmp.push_back(carry);
        
        std::reverse(tmp.begin(), tmp.end());

        for(int i : tmp)
            res.insert(i);
    }

}

void test_1()
{
    LinkedList<int> ll1, ll2, res;
    
    ll1.insert(7);
    ll1.insert(1);
    ll1.insert(6);
     
    ll2.insert(5);
    ll2.insert(9);
    ll2.insert(2);
    ll1.print();
    ll2.print();
    
    int carry = 0;

    addBackwards(ll1.head(),ll2.head(),res,carry);

    res.print();
}

void test_2()
{
    LinkedList<int> ll1, ll2, res;
    
    ll1.insert(6);
    ll1.insert(1);
    ll1.insert(7);
     
    ll2.insert(4);
    ll2.insert(9);
    ll2.insert(5);
    ll1.print();
    ll2.print();
    
    int carry = 0,step=0;
    std::vector<int> tmp;
    addForward(ll1.head(),ll2.head(),res,carry,step,tmp);

    res.print();
}

int main(void)
{
    test_2(); 
    return 0;
}

