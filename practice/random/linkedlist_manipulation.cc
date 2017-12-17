#include <iostream>
#include "../data_structures/linkedlist.h"

LinkedList* create_linked_list(){
    
    LinkedList * ll = new LinkedList();

    for(int i =0; i<10; i++){
        ll->insert(i);
    }
    return ll;
}

LinkedList* reverse(LinkedList * ll){
    std::cout<<"Pre-reversal\n";
    ll->print();

    Node *curr=ll->get_head(), *next=NULL,*prev=NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }    
    
    ll->set_head(prev);
    std::cout<<"Post-reversal\n";
    ll->print();
    return ll;
}

int main(void){
    LinkedList *ll = create_linked_list();
    reverse(ll);
    return 0;
}
