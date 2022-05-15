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
    
    void preorder(TreeNode *root,int &res,int lvl,int h)
    {
        if(!root)
            return;
        if(!root->left and !root->right and lvl==h)
        {
            res+=root->val;
            return;
        }
        preorder(root->left,res,lvl+1,h);
        preorder(root->right,res,lvl+1,h);
    }
    
    int height(TreeNode *root)
    {
        return !root?0:1+max(height(root->left),height(root->right));
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        int res = 0;
        preorder(root,res,1,h);
        return res;
    }
};