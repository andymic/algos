#include "stack.h"
#include <iostream>


Stack::Stack(int s){
   max = s;
   ar=new int[s];
   pos = 0;
}

int Stack::push(int item){
    if(pos>=max){
        std::cout<<"Error stack is full...element not inserted\n";
        return -1;
    }
    
    ar[pos++]=item;
    std::cout<<"Pushed element: "<<ar[pos-1]<<" at index: "<<pos-1<<std::endl;
    return pos-1;
}

int Stack::pop(){
    if(pos<=0){
        std::cout<<"Error: stack is empty...no element to retrieve\n";
        return -1;
    }

    int val = ar[pos-1];
    std::cout<<"Popping element: "<<val<<" at index "<<pos-1<<std::endl;
    ar[pos--]= 0;
    return val;
}

int Stack::size(){
    return pos;
}

int Stack::capacity(){
    return max;
}

void Stack::print(){
    int curr = pos-1;

    while(curr>=0)
        std::cout<<ar[curr]<<std::endl, curr--;

    std::cout<<"Capacity: "<<capacity()<<", Size: "<<size()<<std::endl;
}
