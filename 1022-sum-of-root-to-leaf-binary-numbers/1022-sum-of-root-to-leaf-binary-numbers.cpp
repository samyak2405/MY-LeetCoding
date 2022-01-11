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
    
    void solve(TreeNode *root,int curr,int &sum)
    {
        if(!root)
            return;
        curr = (curr<<1)|root->val;
        if(!root->left and !root->right)
        {
            sum+=curr;
            return;
        }
        solve(root->left,curr,sum);
        solve(root->right,curr,sum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        solve(root,0,sum);
        return sum;
    }
};