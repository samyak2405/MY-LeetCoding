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
    
    void preorder(TreeNode *root,vector<vector<int>> &v1,vector<int> tmp,int sum)
    {
        if(!root)
            return;
        sum+=root->val;
        tmp.push_back(root->val);
        if(!root->left and !root->right)
        {
            tmp.push_back(sum);
            v1.push_back(tmp);
        }
        else
        {
            preorder(root->left,v1,tmp,sum);
            preorder(root->right,v1,tmp,sum);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res,v1;
        if(!root)
            return res;
        preorder(root,v1,vector<int>(),0);
        for(auto it:v1)
        {
            if(it.back()==targetSum)
            {
                it.pop_back();
                res.push_back(it);
            }
        }
        return res;
    }
};