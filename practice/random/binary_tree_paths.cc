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
    bool isLeaf(TreeNode* root){
        return (root->left== NULL && root->right == NULL);
    }

    void combinePath(TreeNode* root, string buff, vector<string>& vec, bool isFirst){
        if(root == NULL)
            return;

        if(isFirst)
            buff+=to_string(root->val);
        else
            buff+="->"+to_string(root->val);

        if(isLeaf(root))
            vec.push_back(buff);


        combinePath(root->left, buff, vec, false);
        combinePath(root->right, buff, vec, false);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string buff;

        combinePath(root, buff, res, true);

        return res;

    }
};
