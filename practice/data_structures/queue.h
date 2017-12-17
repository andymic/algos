#include<iostream>
#include<vector>

class Queue{
    private:
        std::vector<int> queue;
    public:
        Queue(int size);
        Queue();
        void enqueue(int item);
        int dequeue();
        int size();
        int capacity();
        void print();
};
