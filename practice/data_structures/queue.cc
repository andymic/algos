#include "queue.h"
#include <iostream>

Queue::Queue(int size){
    queue.resize(size);
}

Queue::Queue(){

}

void Queue::enqueue(int item){
    std::cout<<"Enqueue item: "<<item<<std::endl;
    queue.push_back(item);
}

int Queue::dequeue(){
   int val =  queue.front(); 
   std::cout<<"Dequeued item: "<<val<<std::endl;
   queue.erase(queue.begin());
   return val;
}

int Queue::size(){
    return queue.size();
}

int Queue::capacity(){
    return queue.capacity();
}

void Queue::print(){
    for(auto const& it: queue)
        std::cout<<it<<"->";

    std::cout<<"\nCapacity: "<<capacity()<<", Size: "<<size()<<std::endl;
}
