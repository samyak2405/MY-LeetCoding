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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,int>> q;
        q.push({root,1});
        int width = INT_MIN;
        while(!q.empty())
        {
            int sz = q.size();
            int fi,sec;
            int zero = q.front().second;
            for(int i = 0;i<sz;i++)
            {
                pair<TreeNode *,int> p= q.front();
                q.pop();
                TreeNode *node = p.first;
                unsigned int k = p.second-zero;
                if(i==0)
                    fi = k;
                if(i==sz-1)
                    sec = k;
                if(node->left)
                    q.push({node->left,k*2});
                    
                if(node->right)
                    q.push({node->right,k*2+1});
            }
            width = max(width,sec-fi+1);
        }
        return width;
    }
};