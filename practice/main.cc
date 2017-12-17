#include "data_structures/linkedlist.h"
#include "data_structures/stack.h"
#include "data_structures/queue.h"
#include "data_structures/binary_search_tree.h"
#include <iostream>

using namespace std;

void linked_list(){
    
    LinkedList * ll = new LinkedList();

    for(int i =0; i<10; i++){
        ll->insert(i);
    }

    ll->print_backward();
    //cout<<ll->get_middle()->data;
}

void stack(){
    int size = 10;
    Stack * stack = new Stack(size);
    
    for(int i=0; i<size; i++)
        stack->push(i);
    
    //error
    stack->push(11);

    cout<<endl;
    
    for(int i=0; i<size; i++)
        stack->pop();
    
    //error
    stack->pop();
}

void queue(){
    int size = 10;
    Queue * queue = new Queue();

    for(int i=0; i<size; i++)
        queue->enqueue(i);

    cout<<endl;
    queue->print();

    for(int i=0; i<size; i++)
        queue->dequeue();
}

void bst(){
   //int ar[]={0,1,2,3,4,5,6,7,8,9,10,11,12};

	int tree[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
    BinarySearchTree *bst = new BinarySearchTree();
    BNode * t = NULL;
    t = bst->insert(t,tree[0]);
    
    for(int i=1; i<16; i++){
        bst->insert(t, tree[i]);
    }

    bst->print();

    cout<<endl;
    cout<<"Enter a key to search in tree"<<endl;
    int key;
    cin>>key;
    bst->search(t, key);

    cout<<"\nEnter a key to remove in tree"<<endl;
    cin>>key;
    bst->remove(t, key);
    cout<<endl;
    bst->print();
}

int main(void){
    linked_list();
    return 0;    
}
