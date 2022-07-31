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
    int res = 0;
public:
    
    int f(TreeNode *root)
    {
        if(!root)
            return 2;
        int l = f(root->left),r = f(root->right);
        if(l==0 or r==0)
        {
            res++;
            return 1;
        }
        return (l==1 or r==1)?2:0;
    }
    
    int minCameraCover(TreeNode* root) {
        return (f(root)==0?1:0) + res;
        return res;
    }
};