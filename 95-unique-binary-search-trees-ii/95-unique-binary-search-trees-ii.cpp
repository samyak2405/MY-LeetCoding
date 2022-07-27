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
    
    vector<TreeNode *> f(int l,int r)
    {
        vector<TreeNode *> res;
        if(l>r)
        {
            res.push_back(NULL);
            return res;
        }
        if(l==r)
        {
            res.push_back(new TreeNode(l));
            return res;
        }
        for(int i = l;i<=r;i++)
        {
            auto left = f(l,i-1);
            auto right = f(i+1,r);
            for(auto lt:left)
            {
                for(auto rt:right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    res.push_back(root);
                }
            }
        }
        return res;
    } 
    
    vector<TreeNode*> generateTrees(int n) {
        return f(1,n);
    }
};