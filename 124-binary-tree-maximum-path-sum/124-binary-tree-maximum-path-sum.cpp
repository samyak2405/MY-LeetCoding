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
    
    int solve(TreeNode *root,int &res)
    {
        if(!root)
            return 0;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        int tmp = max(root->val,max(l,r)+root->val);
        int ans = max(tmp,root->val+l+r);
        res = max(res,ans);
        return tmp;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};