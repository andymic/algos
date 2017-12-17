/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void find(TreeNode* root, TreeNode* p, vector<TreeNode*>& path){
        if(root == NULL){
            return;
        }

        path.push_back(root);

        if(root->val == p->val){
            return;
        }

        if(p->val < root->val)
            find(root->left, p, path);
        else
            find(root->right, p, path);
    }
public:
  TreeNode* lowestCommonAncestorBest(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == NULL)
           return NULL;

       if(p->val < root->val && root->val > q->val)
          return lowestCommonAncestor(root->left, p, q);
       else if(p->val > root->val && root->val < q->val)
           return lowestCommonAncestor(root->right, p, q);

       return root;
   }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pa;
        vector<TreeNode*> qa;

        find(root, p, pa);
        find(root, q, qa);

        int len = (pa.size() < qa.size())? pa.size() : qa.size();
        TreeNode* cp =NULL;

        for(int i=0; i<len; i++){
            if(pa[i]->val == qa[i]->val)
                cp = pa[i];
        }

        return cp;
    }
};
