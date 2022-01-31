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
    
    void preorder(TreeNode *root,TreeNode *par,TreeNode *&parent,int x,int h,int &height)
    {
        if(!root)
            return;
        if(root->val==x)
        {
            parent = par;
            height = h;
            return;
        }
        preorder(root->left,root,parent,x,h+1,height);
        preorder(root->right,root,parent,x,h+1,height);
    }
        
    
    bool isCousins(TreeNode* root, int x, int y) {
        int h1,h2;
        TreeNode *parent1,*parent2;
        
        preorder(root,NULL,parent1,x,1,h1);
        preorder(root,NULL,parent2,y,1,h2);
        
        if(h1==h2 and parent1!=parent2)
            return true;
        
        return false;
    }
};