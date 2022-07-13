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
    
    TreeNode *f(vector<int> &nums,int l,int r)
    {
        if(l>r)
            return NULL;
        int maxi = INT_MIN,j = 0;
        for(int i = l;i<=r;i++)
        {
            if(maxi<nums[i])
            {
                maxi = nums[i];
                j = i;
            }
        }
        TreeNode *newnode = new TreeNode(maxi);
        newnode->left = f(nums,l,j-1);
        newnode->right = f(nums,j+1,r);
        return newnode;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return f(nums,0,nums.size()-1);
    }
};