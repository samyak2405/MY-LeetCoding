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
    
    void preorder(TreeNode *root,vector<string> &res,string s)
    {
        if(!root)
            return;
        s+=to_string(root->val);
        if(!root->left and !root->right)
        {
            res.push_back(s);
            return;
        }
        preorder(root->left,res,s+"->");
        preorder(root->right,res,s+"->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        preorder(root,res,"");
        return res;
    }
};