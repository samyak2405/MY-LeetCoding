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
    
    void preorder(TreeNode *root,int lvl,bool &flag,int &value)
    {
        if(!root)
            return;
        if(lvl==1)
        {
            if(flag)
            {
                value = root->val;
                flag = false;
            }
            return;
        }
        preorder(root->left,lvl-1,flag,value);
        preorder(root->right,lvl-1,flag,value);
    }
    
    int height(TreeNode *root)
    {
        return !root?0:1+max(height(root->left),height(root->right));
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int h = height(root);
        int value = -1;
        bool flag = true;
        preorder(root,h,flag,value);
        return value;
    }
};