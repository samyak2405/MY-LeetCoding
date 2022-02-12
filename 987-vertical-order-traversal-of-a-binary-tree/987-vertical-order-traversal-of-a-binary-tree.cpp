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
    
    void preorder(TreeNode *root,map<int,vector<pair<int,int>>> &pq,int h,int lvl)
    {
        if(!root)
            return;
        pq[h].push_back({lvl,root->val});
        preorder(root->left,pq,h-1,lvl+1);
        preorder(root->right,pq,h+1,lvl+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>> res;
        map<int,vector<pair<int,int>>> pq;
        
        preorder(root,pq,0,0);
        
        for(auto it:pq)
        {
            sort(it.second.begin(),it.second.end());
            vector<int> tmp;
            for(auto itr:it.second)
                tmp.push_back(itr.second);
            res.push_back(tmp);
        }
        
        return res;
    }
};