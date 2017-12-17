#include "linkedlist.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head = NULL;
}

Node *LinkedList::get_head(){
    return head;
}

void LinkedList::set_head(Node* phead){
    head = phead;
}
void LinkedList::insert(int data){
    
    struct Node * temp = new Node();
    temp->data = data;
    temp->next = NULL;
    
    if(head == NULL){
        head = temp;
        return;    
    }
    
    struct Node * t = head;

    while(t->next != NULL){
        t = t->next;
    }

    t->next = temp;
}

Node *LinkedList::find(int data){
    struct Node * temp = head;

    while(temp != NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void LinkedList::remove(int data){
    struct Node * prev=head;
    struct Node * curr=head;

    if(curr != NULL && curr->data == data){
        if(curr->next == NULL){
            curr = NULL;
        }
        else{
            struct Node * temp = curr->next;
            curr->data = temp->data;
            curr->next = temp->next;
            delete temp;
        }
        return;
    }

    while(curr != NULL && curr->data != data){
        prev = curr;
        curr = curr->next;
    }
    
    if(curr == NULL){
        return;
    }

    prev->next = curr->next;
    delete curr;
}

void LinkedList::print(){
    Node * temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<endl;
}

void print_backwards(Node* start){
    if(start == NULL){
        return;
    }

    print_backwards(start->next);
    cout<<start->data<<"->";
}


void LinkedList::print_backward(){
    print_backwards(head);
    cout<<endl;
}

Node * LinkedList::get_middle(){
    struct Node * slow = head;
    struct Node * fast = head;

    if(slow == NULL)
        return NULL;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}
