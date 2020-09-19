#include<iostream>
#include "list.h"

void test_1()
{
    LinkedList<int> ll;
    
    for(int i=0; i<10; i++)
        ll.insert(i);

    ll.print();

    std::cout<<"Find [7]: "<<std::to_string(ll.find(7)->data)<<std::endl;

    std::cout<<"Delete [0]: ";
    ll.remove(0);
    ll.print();
}

void test_2()
{
    LinkedList<char> ll;
    
    for(int i=97; i<107; i++)
        ll.insert((char)i);

    ll.print();

    std::cout<<"Find [e]: "<<std::to_string(ll.find('e')->data)<<std::endl;

    std::cout<<"Delete [f]: ";
    ll.remove('e');
    ll.print();
}

int main(void)
{
    test_1();
    test_2();
    return 0;
}

