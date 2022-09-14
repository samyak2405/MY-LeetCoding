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
    int res =0;
    unordered_map<int,int> mp;
    void preorder(TreeNode *root)
    {
        if(!root)
            return;
        mp[root->val]++;
        if(!root->left and !root->right)
        {
            int cnt = 0;
            for(auto a:mp)
                if((a.second%2)==1)
                    cnt++;
            if(cnt<=1)
                res++;
        }
        preorder(root->left);
        preorder(root->right);
        mp[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root);
        return res;
    }
};