#include<iostream>
#include<vector>
#include<unordered_set>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct Node {
    Node * next;
    int data;
};

Node *makeNode(int data){
    Node *t = new Node();
    t->data = data;
    t->next = NULL;
    return t;
}

void printList(Node *head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

Node* removeDuplicates(Node * head){
    if(head == NULL)
        return NULL;

    unordered_set<int> buf;
    Node *prev = NULL;
    Node *curr = head;

    while(curr != NULL){
        if(buf.find(curr->data) == buf.end()){
            buf.insert(curr->data);
        }else{
            prev->next = curr->next;
            curr = prev;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

Node * removeDuplicates2(Node *head){
    if(head == NULL)
        return NULL;

    Node *curr = head;

    while(curr != NULL){
        Node *runner  = curr;

        while(runner->next != NULL){
            if(runner->next->data == curr->data){
                runner->next = runner->next->next;
            }else{
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

Node* findKthToLast(Node *head, int &k){
    if(head == NULL)
        return NULL;

    Node *p = findKthToLast(head->next, k);
    k--;
    if(k == 0)
        return head;

    return p;
}

Node* findKthToLast2(Node *head, int k){
    if(head == NULL)
        return NULL;

    Node *p1 = head;
    Node *p2 = head;

    for(int i=0; i<k; i++){
        if(p2 == NULL)
            return NULL;
        p2 = p2->next;
    }   

    if(p2 == NULL)
        return NULL;

    while(p2){
        p2 = p2->next;
        p1 = p1->next;
    }
    return p1;
}

void deleteMiddle(Node *middle){
    if(middle == NULL)
       return;
   
   Node *prev = NULL;
   while(middle->next != NULL){
       middle->data = middle->next->data;
       prev = middle;
       middle = middle->next;
   } 
   
   prev->next = NULL;
}

Node* partition(Node *head, int x){
    Node *left=NULL, *hleft=NULL, *right=NULL, *hright=NULL, *middle=NULL;
    
    Node *curr = head;
    while(curr != NULL){
        if(curr->data < x){
            if(hleft == NULL){
                left = makeNode(curr->data);
                hleft = left;
            }
            else{
                left->next = makeNode(curr->data);
                left = left->next;
            }
        }
        else if(curr->data == x){
           middle = makeNode(curr->data);
        }
        else{
            if(hright == NULL){
                right = makeNode(curr->data);
                hright = right;
            }else{
                right->next = makeNode(curr->data);
                right = right->next;
            }
        }
        curr = curr->next;
    }

    left->next = middle;
    middle->next = hright;
    head = hleft;
    return head;
}

Node* addForward(Node *a, Node *b){
    int remainder = 0;
    vector<int> buf;
    int oper = 0;

    // a and b are of the same length
    
    Node * t = a;
    int count = 0;

    while(t != NULL)
        count++, t=t->next;
    
    while(a != NULL && b != NULL){
        count--;
        oper = a->data + b->data + remainder;
        
        
        if(oper >= 10 &&  count != 0){
            remainder = oper /10;
            oper = oper % 10;
        }
        else
            remainder = 0;

        cout<<"oper: "<<oper<<" rm: "<<remainder<<endl;
        buf.push_back(oper);

        a = a->next;
        b = b->next;
    }

    reverse(buf.begin(), buf.end());
    
    Node * result = makeNode(buf.at(0));
    Node * hresult = result;
    for(int i=1; i<buf.size(); i++){
        result->next = makeNode(buf.at(i));
        result = result->next;
    }

    return hresult;
}

void addBackward(Node *a, Node *b, int &remainder, vector<int> &result, int &count){
    if(a == NULL || b == NULL)
        return;

    addBackward(a->next, b->next, remainder, result, count);
    
    int oper = a->data + b->data + remainder;
    count--;
    if(oper >= 10 && count > 0){
        remainder = oper /10;
        oper = oper % 10;
    }
    else
        remainder = 0;
    
    result.push_back(oper);
}

Node * addBackward(Node *a, Node *b){
    Node * t = a;
    int count = 0;
    vector<int> result;
    int remainder = 0;
    while(t != NULL)
        count++, t=t->next;

    addBackward(a, b, remainder, result, count);

    reverse(result.begin(), result.end());
    
    Node *node = makeNode(result.at(0));
    Node *hnode = node;
    for(int i=1; i<result.size(); i++){
        node->next = makeNode(result.at(i));
        node = node->next;
    }
    return hnode;
}

Node* getLoopHead(Node *n){
    Node *stop = n;
    Node *run = n;

    if(run->next == NULL)
        return NULL;

    while(run->next != stop)
        run = run->next;

    return run->next;
}

void testRemoveDuplicates(){
    Node *n = makeNode(0);
    Node *t = n;
    for(int i=0; i<10; i++){
        t->next = makeNode(i);
        t=t->next;
    }
    t->next = makeNode(5);
    
    cout<<"Before remove: ";
    printList(n); 
    Node *r = removeDuplicates(n); 
    cout<<"After remove removeDuplicates: ";
    printList(r);
    r = removeDuplicates2(n);
    cout<<"After remove removeDuplicates2: ";
    printList(r);
}

void testFindKthToLast(Node *n){
    int k=5;
    cout<<"FindKthToLast - K: "<<k<<endl;
    printList(n);
    Node *r  = findKthToLast2(n, k);
    cout<<r->data<<endl;
}

void testDeleteMiddle(Node* head, int len){
    Node *n = head;
    for(int i=0; i<len/2; i++){
        if(n != NULL)
            n = n->next;
    }
    
    cout<<"Before removing middle: ";
    printList(head);
    deleteMiddle(n);
    cout<<"After removing middle: ";
    printList(head);
}

void testPartition(){
    int rnd = rand()%100;
    Node *n = makeNode(rnd);
    Node *t = n;
    int x;
    for(int i=0; i<20; i++){
        rnd = rand()%100;
        t->next = makeNode(rnd);
        t=t->next;
        
        if(i == 10)
            x = rnd;

    }
    
    cout<<"Partition, x: "<<x<<endl;
    printList(n);
    Node *r = partition(n, x);
    printList(r);
}

void testAddForward(){
    int a[] = {7,1,6};
    int b[] = {5,9,2};
    Node *na = makeNode(a[0]);
    Node *nb = makeNode(b[0]);
    Node * ta = na;
    Node * tb = nb;
    for(int i=1; i<3; i++){
        ta->next = makeNode(a[i]);
        tb->next = makeNode(b[i]);
        ta = ta->next;
        tb =  tb->next;
    }
    
    printList(na);
    printList(nb);
    Node * r = addForward(na, nb);
    printList(r);
}

void testAddiBackward(){
    int a[] = {6,1,7};
    int b[] = {2,9,5};
    Node *na = makeNode(a[0]);
    Node *nb = makeNode(b[0]);
    Node * ta = na;
    Node * tb = nb;
    for(int i=1; i<3; i++){
        ta->next = makeNode(a[i]);
        tb->next = makeNode(b[i]);
        ta = ta->next;
        tb =  tb->next;
    }
    
    printList(na);
    printList(nb);
    Node * r = addBackward(na, nb);
    printList(r);
}

int main(void){
    Node *n = makeNode(0);
    Node *t = n;
    for(int i=0; i<10; i++){
        t->next = makeNode(i);
        t=t->next;
    }
    t->next = n->next;

    Node * r = getLoopHead(n);
    cout<<r->data<<endl;
    return 0;
}
