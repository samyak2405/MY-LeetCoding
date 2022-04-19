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
    
    void inorder(TreeNode *root,vector<int> &nums)
    {
        if(!root)
            return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        vector<int> nums;
        inorder(root,nums);
        for(int i = 1;i<nums.size();i++)
            if(nums[i]==nums[i-1])
                return false;
        return is_sorted(nums.begin(),nums.end());
    }
};