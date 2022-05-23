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
    void preorder(TreeNode *root,vector<int> &res)
    {
        if(!root)
            return;
        if(!root->left and !root->right)
            res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        preorder(root1,v1);
        preorder(root2,v2);
        return v1==v2;
    }
};