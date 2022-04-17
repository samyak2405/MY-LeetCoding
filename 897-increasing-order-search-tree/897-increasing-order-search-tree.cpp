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
    
    void inorder(TreeNode *root,vector<int> &v1)
    {
        if(!root)
            return;
        inorder(root->left,v1);
        v1.push_back(root->val);
        inorder(root->right,v1);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *newRoot = new TreeNode();
        newRoot->left =NULL;
        TreeNode *p = newRoot;
        vector<int> v1;
        inorder(root,v1);
        for(int i = 0;i<v1.size();i++)
        {
            p->right = new TreeNode(v1[i]);
            p->left = NULL;
            p = p->right;
        }
        return newRoot->right;
    }
};