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
    #define vi vector<int>
    #define map unordered_map<int,int>
    
    TreeNode *build(vi &postorder,int postStart,int postEnd,vi &inorder,int inStart,int inEnd,map &mp)
    {
        if(postEnd<postStart or inStart>inEnd)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        int inroot = mp[root->val];
        int numsOnleft = inroot - inStart;
        
        root->left = build(postorder,postStart,postStart+numsOnleft-1,inorder,inStart,inroot-1,mp);
        root->right = build(postorder,postStart+numsOnleft,postEnd-1,inorder,inroot+1,inEnd,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n = postorder.size();
        for(int i = 0;i<n;i++)
            mp[inorder[i]] = i;
        TreeNode *root = build(postorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
};