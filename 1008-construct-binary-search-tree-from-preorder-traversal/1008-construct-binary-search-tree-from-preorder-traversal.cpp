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
    
    TreeNode *build(int &i,vector<int> &preorder,int mini,int maxi)
    {
        if(i>=preorder.size())
            return NULL;
        if(preorder[i]<mini or preorder[i]>maxi)
            return NULL;
        TreeNode *newnode = new TreeNode(preorder[i++]);
        newnode->left = build(i,preorder,mini,newnode->val);
        newnode->right = build(i,preorder,newnode->val,maxi);
        return newnode;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(i,preorder,INT_MIN,INT_MAX);
    }
};