/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findparent(TreeNode *root,unordered_map<TreeNode *,TreeNode *> &mp)
    {
        if(!root)
            return;
        if(root->left)
        {
            mp[root->left] = root;
            findparent(root->left,mp);
        }
        if(root->right)
        {
            mp[root->right] = root;
            findparent(root->right,mp);
        }
    }
    
    void finddist(TreeNode *root,int k,unordered_set<TreeNode *> &s1,unordered_map<TreeNode *,TreeNode *> &mp,vector<int> &res)
    {
        if(!root)
            return;
        if(s1.find(root)!=s1.end())
            return;
        s1.insert(root);
        if(k==0)
            res.push_back(root->val);
        if(root->left)
            finddist(root->left,k-1,s1,mp,res);
        if(root->right)
            finddist(root->right,k-1,s1,mp,res);
        TreeNode *p = mp[root];
        if(p)
            finddist(p,k-1,s1,mp,res);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(!root)
            return res;
        unordered_map<TreeNode *,TreeNode *> mp;
        unordered_set<TreeNode *> s1;
        findparent(root,mp);
        finddist(target,k,s1,mp,res);
        return res;
    } 
};