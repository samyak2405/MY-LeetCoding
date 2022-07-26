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
    
    TreeNode * LCA(TreeNode *root,int p,int q)
    {
        if(!root or root->val==p or root->val==q)
            return root;
        TreeNode *l = LCA(root->left,p,q);
        TreeNode *r = LCA(root->right,p,q);
        if(!l)
            return r;
        if(!r)
            return l;
        return root;
    }

    bool preorder_(TreeNode *root,int d,string &s)
    {
        if(!root)
            return false;
        if(root->val==d)
            return true;
        s.push_back('L');
        bool l = preorder_(root->left,d,s);
        if(l)
            return true;
        s.pop_back();
        s.push_back('R');
        bool r = preorder_(root->right,d,s);
        if(r)
            return true;
        s.pop_back();
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string res1,res2;
        TreeNode *ancestor = LCA(root,startValue,destValue);
        preorder_(ancestor,startValue,res1);
        for(auto &it:res1)
            it ='U';
        preorder_(ancestor,destValue,res2);
        return res1+res2;
    }
};