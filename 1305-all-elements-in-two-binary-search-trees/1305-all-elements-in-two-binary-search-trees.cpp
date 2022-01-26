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
    
    void preorder(TreeNode *root,vector<int> &v1)
    {
        if(!root)
            return;
        v1.push_back(root->val);
        preorder(root->left,v1);
        preorder(root->right,v1);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        if(!root1 and !root2)
            return v1;
        preorder(root1,v1);
        preorder(root2,v1);
        sort(v1.begin(),v1.end());
        return v1;
    }
};