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
    #define map unordered_map<int,int>
    #define vi vector<int>
    
    TreeNode *build(vi &preorder,int preStart,int preEnd,vi &inorder,int inStart,int inEnd,map &mp)
    {
        if(preStart>preEnd or inStart>inEnd)
            return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        
        int inRoot = mp[root->val];
        int numsOnLeft = inRoot-inStart;
        
        root->left = build(preorder,preStart+1,preStart+numsOnLeft,inorder,inStart,inRoot-1,mp);
        root->right = build(preorder,preStart+numsOnLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map mp;
        int n = preorder.size();
        for(int i = 0;i<n;i++)
            mp[inorder[i]] = i;
        TreeNode *root = build(preorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
};