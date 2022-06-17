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
    
    int dfs(TreeNode *root)
    {
        if(!root)
            return 2;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left==0 or right==0)
        {
            res++;
            return 1;
        }
        return left==1 or right==1?2:0;
    }
    
    int minCameraCover(TreeNode* root) {
        
        return (dfs(root)<1?1:0)+res;
    }
};