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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        stack<TreeNode *> s1;
        TreeNode *prev = NULL;
        
        while(root or !s1.empty())
        {
            while(root)
            {
                s1.push(root);
                root = root->left;
            }
            root = s1.top();
            s1.pop();
            if(prev and root->val<=prev->val)
                return false;
            prev = root;
            root = root->right;
        }
        
        return true;
    }
};