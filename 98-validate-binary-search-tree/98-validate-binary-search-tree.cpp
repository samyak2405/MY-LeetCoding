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
        stack<TreeNode *> s1;
        TreeNode *prev = NULL;
        while(!s1.empty() or root)
        {
            while(root)
            {
                s1.push(root);
                root = root->left;
            }
            root = s1.top();
            s1.pop();
            if(prev and prev->val>=root->val)
                return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};