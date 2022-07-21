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
    
    pair<int,int> f(TreeNode *root,int &res)
    {
        if(!root)
            return {0,0};
        if(!root->left and !root->right)
        {
            res++;
            return {root->val,1};
        }
        pair<int,int> l = f(root->left,res);
        pair<int,int> r = f(root->right,res);
        int sum = l.first+r.first+root->val;
        int cnt = l.second+r.second+1;
        int avg = sum/cnt;
        if(avg == root->val)
            res++;
        
        return {sum,cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        f(root,res);
        return res;
    }
};