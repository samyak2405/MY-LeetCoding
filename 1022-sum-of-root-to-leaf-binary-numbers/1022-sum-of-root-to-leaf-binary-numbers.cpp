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
    
    int strtoint(string s)
    {
        reverse(s.begin(),s.end());
        int x =0,j = 0;
        for(auto it:s)
        {
            if(it=='1'){
                x+=pow(2,j);
            }
            j++;
        }
        return x;
    }
    
    void solve(TreeNode *root,string s,int &sum)
    {
        if(!root)
            return;
        s+=to_string(root->val);
        if(!root->left and !root->right)
        {
            sum += strtoint(s);
            return ;
        }
        solve(root->left,s,sum);
        solve(root->right,s,sum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        solve(root,"",sum);
        return sum;
    }
};