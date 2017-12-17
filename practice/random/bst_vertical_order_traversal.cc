#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* newNode(int x) {
    return new TreeNode(x);
}
void findMinMax(TreeNode* root, int *min, int *max, int hd) {
    if(root == NULL)
        return;

    if(hd<*min) {
        *min = hd;
    }
    else if(hd>*max) {
        *max = hd;
    }

    findMinMax(root->left, min, max, hd-1);
    findMinMax(root->right, min, max, hd+1);
}

void addVerticalNode(TreeNode* root, int line_no, int hd, vector<int>& buff) {
    if(root == NULL)
        return;

    if(line_no == hd) {
        buff.push_back(root->val);
    }

    addVerticalNode(root->left, line_no, hd-1, buff);
    addVerticalNode(root->right, line_no, hd+1, buff);
}
vector<vector<int>> verticalOrder(TreeNode* root) {
    int min =0;
    int max = 0;

    findMinMax(root, &min,& max, 0);
    vector<vector<int>> result;

    for(int line = min; line<= max; line++) {
        vector<int> temp;
        addVerticalNode(root, line, 0, temp);
        result.push_back(temp);
    }
    return result;
}

void print(vector<vector<int>> result){
  for(vector<int> v : result){
      for(auto i: v)
          cout<<i<<" ";

      cout<<endl;
  }
}

void level_order_print(TreeNode* root){
    TreeNode* temp = root;
    int curr_level = 1, next_level = 0;
    queue<TreeNode*> nodes;
    nodes.push(temp);

    while(!nodes.empty()){
        TreeNode* n = nodes.front();
        nodes.pop();

        curr_level--;

        if(n!=NULL){
            cout<<n->val<<" ";
            nodes.push(n->left);
            nodes.push(n->right);
            next_level+=2;   
        }

        if(curr_level == 0){
            curr_level = next_level;
            next_level = 0;
            cout<<endl;
        }

    }

}
int main(void) {
    TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(0);
    root->right->left = newNode(1);
    root->right->right = newNode(7);
    root->right->left->left = newNode(5);
    root->left->right->right = newNode(2);
    //root->right->left->right = newNode(2);

    vector<vector<int>> result = verticalOrder(root);
    level_order_print(root);
    //print(result);
     return 0;
}
