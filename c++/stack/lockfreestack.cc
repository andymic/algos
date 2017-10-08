/**
 * @Author: Michel Andy <andy>
 * @Date:   2017-09-26T22:42:45-04:00
 * @Email:  Andymic12@gmail.com
 * @Project: Multicore Programming 
 * @Filename: lockfreestack.cc
 * @Last modified by:   andy
 * @Last modified time: 2017-09-26T22:48:26-04:00
 */



#include<iostream>
#include<atomic>
#include<thread>
#include<vector>
#include<chrono>

template<typename T>
struct Node{
    T val;
    Node<T> *next;
};


template<class T>
class Stack{
    private:
        std::atomic<Node<T> *> head;
        int numOps;

        Node<T> *createNode(T val){
            Node<T> *n = new Node<T>;
            n->val = val;
            n->next = NULL;
            return n;
        }
    public:
        Stack(){
            numOps = 0;
            head = NULL;
        }

        bool push(T x){
            Node<T> *n = createNode(x);
            std::cout<<"Push oper by thread: "<<std::this_thread::get_id()<<std::endl;       
            do{
                numOps++;
                //in case another thread has updated head and the compare_exchange fails
                //then update n->next to point to new head
                n->next = head.load();
                
            }while(!head.compare_exchange_weak(n->next, n));
            
            return true;
        }

        T pop(){
            if(head == NULL)
                throw "Empty stack!!";

            Node<T> *n; 
            
            std::cout<<"Pop oper by thread: "<<std::this_thread::get_id()<<std::endl;       
            do{
                numOps++;
                n = head.load();
            }while(!head.compare_exchange_weak(n, n->next));
            return n->val;
        }

        int getNumOps(){
            return numOps;
        }

        void print(){
            Node<T> *n = head;
            while(n != NULL)
                std::cout<<n->val<<" ", n=n->next;

            std::cout<<std::endl;
        }
};

void example1(){
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);

  std::cout<<"numOps: "<<stack.getNumOps()<<std::endl;
  stack.print();
  stack.pop();
  stack.print();
  std::cout<<"numOps: "<<stack.getNumOps()<<std::endl;
  stack.pop();
  stack.print();
  std::cout<<"numOps: "<<stack.getNumOps()<<std::endl;
  stack.pop();
  stack.print();
  std::cout<<"numOps: "<<stack.getNumOps()<<std::endl;
}

void push_func(Stack<int> &stack, int idx){
    for(int i=idx; i<idx+5; i++)
        stack.push(i);
}

void pop_func(Stack<int> &stack){
    for(int i=0; i<2; i++)
        stack.pop();
}

void example2(){
    std::vector<std::thread> ths;
    Stack<int> stack;

    for(int i=0; i<5; i++)
        ths.push_back(std::thread(push_func, std::ref(stack), i*10));

    //for(int i=0; i<5; i++)
      //  ths.push_back(std::thread(pop_func, std::ref(stack)));
    
    for(int i=0; i<5; i++)
        ths.at(i).join();

    //std::this_thread::sleep_for(std::chrono::seconds(5));
    //std::cout<<stack.getNumOps()<<std::endl;
    //stack.print();


    //for(int i=5; i<10; i++)
      //  ths.at(i).join();

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<stack.getNumOps()<<std::endl;
    stack.print();
}


int main(void){
    example2();
    return 0;
}
