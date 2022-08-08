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
    
    void inorder(TreeNode *root,TreeNode *&prev,TreeNode *&first,TreeNode *&second)
    {
        if(!root)
            return;
        inorder(root->left,prev,first,second);
        if (!first && (!prev or prev->val >= root->val)) {
            first = prev;
        }
    
        if (first && prev->val >= root->val) {
            second = root;
        }        
        prev = root;
        inorder(root->right,prev,first,second);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        inorder(root,prev,first,second);
        swap(first->val,second->val);
    }
};