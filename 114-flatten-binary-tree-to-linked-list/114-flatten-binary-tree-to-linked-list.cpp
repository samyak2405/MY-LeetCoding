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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode *> s1;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode *node = s1.top();
            s1.pop();
            if(node->right)
                s1.push(node->right);
            if(node->left)
                s1.push(node->left);
            node->left = NULL;
            if(!s1.empty())
                node->right = s1.top();
            else
                node->right = NULL;
        }
    }
};