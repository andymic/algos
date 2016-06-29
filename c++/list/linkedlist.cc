#include <iostream>
#include <stdexcept>
#include <string>
#include "list.h"

template<typename E> class Node{
private:
static Node<E> * freelist; //A store for deleted nodes
public:
    E element;
    Node * next;
    
    Node(const E& value, Node * next = NULL){
        element = value;
        this.next = next;
    }        
    
    Node(Node * next = NULL){
        this.next = next;
    }
    
    void * operator new(size_t){
        //When a new node is request grab from the freelist if available
        //This can take 1/10th of the time to create a new node
        if(freelist == NULL)
            return ::new Node;
              
        Node<E> * temp = freelist;
        freelist = freelist->next;
        return temp;
    }
    
    void operator delete(void *ptr){
        //placing the new deleted element at the front of freelist
        ((Node<E>*) ptr)->next = freelist;
        //updating the freelist pointer
        freelist = (Node<E>*)ptr;
    }
};

//Initialize freelist head pointer
template<typename E>
Node<E> * Node<E>::freelist = NULL;

template<typename E> class LinkedList : public BaseList<E>{
private:
    Node<E> * head;
    Node<E> * tail;
    Node<E> * curr; //points to the preceding element
    int count;

    void init(){
        head = tail = curr = new Node<E>;
        count = 0;
    }
    
    void removeAll(){
        while(head != NULL){
            curr = head;
            head = head->next;
            delete curr;
        }
    }
public:
    LinkedList(int size = 0){
        init();
    }
    ~LinkedList(){
        removeAll();
    }
    void print() const;
    void clear(){
        removeAll();
        init();
    }
    
    void insert(const E& item){
        //sets the next element to item and set item's next to the next element
        curr->next = new Node<E>(item, curr->next);
        
        if(curr == tail){
            tail = curr->next;
        }
        count++;
    }
    
    void append(const E& item){
        tail = tail->next = new Node<E>(item, NULL);
        count++;
    }
    
    E remove(){
        if(curr->next == NULL)
            throw std::underflow_error("no element in list");
            
        E item = curr->next->element;
        Node<E> * temp = curr->next;
        
        //if the next element is the last element then update tail
        if(tail == curr->next)
            tail = curr;
        
        curr->next = curr->next->next;
        delete temp;
        count--;
        return item;
    }
    
    void moveToFront(){
        curr =  head;
    }
    
    void moveToBack(){
        curr = tail;
    }
    
    void prev(){
        Node<E> * temp = head;
        if(curr == temp)
            return;
            
        while(temp->next != curr)
            temp = temp->next;
        
        curr = temp;
    }
    
    void next(){
        if(curr == tail)
            return;
        
        curr = curr->next;
    }
    
    int length() const{
        return count;
    }
    
    int currPos() const{            
        Node<E> * temp = head;    
        int pos;
        
        for(pos = 0; temp != curr; pos++)
            temp = temp->next;
        
        return count;
    }
    
    void moveToPos(int pos){
        if(pos >=0 && pos > count)
            throw std::range_error("position out of range");
            
        curr = head;
        for(int i = 0; i<pos; i++)
            curr = curr->next;
    }
    
    const E& getValue() const{
        if(curr->next == NULL)
            throw std::underflow_error("no element in list");
            
        return curr->next->element;
    }
};

int main(void){
    
    return 0;
}