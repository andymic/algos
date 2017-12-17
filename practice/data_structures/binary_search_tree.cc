#include "binary_search_tree.h"
#include <vector>
#include <iostream>


BinarySearchTree::BinarySearchTree(){

}

BNode* BinarySearchTree::get_root(){
    return head;
}

BNode* get_node(int data){
    BNode * n = new BNode();
    n->data = data;
    return n;
}

bool is_leaf(BNode *n){
    return (n->left == NULL && n->right == NULL) ? true :false;
}

BNode* BinarySearchTree::insert(BNode * root, int data){
    BNode * temp = get_node(data);

    if(root == NULL){
        root = temp;
        
        if(head==NULL)head=root;

        return root;
    }

    if(data<=root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

BNode* BinarySearchTree::search(BNode *root, int data){
    
    if(root == NULL){
        std::cout<<"Element: "<<data<<" not found in tree\n";
        return NULL;
    }

    if(data == root->data){
        std::cout<<"Found key at "<<root<<std::endl;
        return root;
    }   

    if(data <= root->data)
        search(root->left, data);
    else
        search(root->right, data);
}

BNode * findmax(BNode *root){
    if(root == NULL) return NULL;

    while(root->right != NULL)
        root = root->right;

    return root;
}

BNode *BinarySearchTree::remove(BNode *root, int data){
   //1)parent
   //2)one child
   //3)two children
   
   if(root == NULL)
      return NULL;
   else if(data < root->data)
      root->left = remove(root->left, data);
   else if(data > root->data)
      root->right = remove(root->right, data);
   else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL && root->right != NULL){
            BNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->left != NULL && root->right == NULL){
            BNode * temp = root;
            root = root->left;
            delete temp;
        }
        else{
            BNode * temp = findmax(root->left);
            root = remove(root->left, temp->data);
            root->data = temp->data;
        }
   }
   return root; 
}

void BinarySearchTree::print(){
    std::vector<BNode*> nodes;
    nodes.push_back(head);
    int curr=1, next=0;
    
    while(nodes.size() > 0){
        
        BNode * temp = nodes.front();
        nodes.erase(nodes.begin());
        curr--;

        if(temp!= NULL){
            std::cout<<temp->data<<" ";
            nodes.push_back(temp->left);
            nodes.push_back(temp->right);
            next+=2;
        }
            
        if(curr == 0){
            curr = next;
            next = 0;
            std::cout<<std::endl;
        }
    }
}

