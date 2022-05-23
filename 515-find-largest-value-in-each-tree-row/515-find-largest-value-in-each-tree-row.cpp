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
    
    void preorder(TreeNode *root,int lvl,int &maxi)
    {
        if(!root)
            return;
        if(lvl==1)
        {
            maxi = max(maxi,root->val);
            return;
        }
        preorder(root->left,lvl-1,maxi);
        preorder(root->right,lvl-1,maxi);
    }
    
    int height(TreeNode *root)
    {
        return !root?0:1+max(height(root->left),height(root->right));
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        int h = height(root);
        for(int i = 1;i<=h;i++)
        {
            int maxi = INT_MIN;
            preorder(root,i,maxi);
            res.push_back(maxi);
        }
        return res;
    }
};