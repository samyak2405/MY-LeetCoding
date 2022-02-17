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
    
    bool preorder(TreeNode *root,int sum,int targetSum)
    {
        if(!root)
            return false;
        
        sum+=root->val;
        
        if(!root->left and !root->right)
            if(sum==targetSum)
                return true;
        
        if(preorder(root->left,sum,targetSum))
            return true;
        
        if(preorder(root->right,sum,targetSum))
            return true;
        
        sum-=root->val;
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return preorder(root,0,targetSum);
    }
};