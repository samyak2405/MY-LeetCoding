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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        if(nums.size()==1)
            return new TreeNode(nums[0]);
        int mid = nums.size()/2;
        vector<int> leftv(nums.begin(),nums.begin()+mid);
        vector<int> rightv(nums.begin()+mid+1,nums.end());
        
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(leftv);
        root->right = sortedArrayToBST(rightv);
        
        return root;
    }
};