/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void f(TreeNode *&root,int &value)
    {
        if(!root)
            return;
        f(root->right,value);
        int tmp = root->val;
        value += tmp;
        root->val = value;
        f(root->left,value);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int value = 0;
        f(root,value);
        return root;
    }
};