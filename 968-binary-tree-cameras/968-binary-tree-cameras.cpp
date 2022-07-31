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
    
    int f(TreeNode *root,int &res)
    {
        if(!root)
            return 2;
        int l = f(root->left,res);
        int r = f(root->right,res);
        if(l==0 or r==0)
        {
            res++;
            return 1;
        }
        return (l==1 or r==1)?2:0;
    }
    
    int minCameraCover(TreeNode* root) {
        int res = 0;
        int val = f(root,res);
        return ((val==0)?1:0) + res;
    }
};