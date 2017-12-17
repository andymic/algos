#include <iostream>


class Stack {
    private:
        int *ar;
        int pos;
        int max;
    public:
        Stack(int s);
        int push(int item);
        int pop();
        int size();
        int capacity();
        void print();
};
