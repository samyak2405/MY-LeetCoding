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
    unordered_map<int,vector<TreeNode *>> mp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode *> res;
        if(n==1)
            res.push_back(new TreeNode(0));
        if(mp[n].size())
            return mp[n];
        else
        {
            for(int i = 1;i<n;i+=2)
            {
                int l = i,r = n-i-1;
                auto left = allPossibleFBT(l);
                auto right = allPossibleFBT(r);
                for(auto lt:left)
                {
                    for(auto rt:right)
                    {
                        TreeNode *newnode = new TreeNode(0);
                        newnode->left = lt;
                        newnode->right = rt;
                        res.push_back(newnode);
                    }
                }
            }
        }
        mp[n] = res;
        return res;
    }
};