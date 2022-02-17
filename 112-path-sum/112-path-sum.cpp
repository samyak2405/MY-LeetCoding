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
    
    void preorder(TreeNode *root,int sum,int targetSum,bool &flag)
    {
        if(!root)
            return;
        sum+=root->val;
        if(!root->left and !root->right)
        {
            if(sum==targetSum)
            {
                flag = true;
                return;
            }
        }
        preorder(root->left,sum,targetSum,flag);
        preorder(root->right,sum,targetSum,flag);
        sum-=root->val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        preorder(root,0,targetSum,flag);
        return flag;
    }
};