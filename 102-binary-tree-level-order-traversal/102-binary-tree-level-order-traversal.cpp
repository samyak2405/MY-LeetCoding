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
    typedef vector<vector<int>> vvi;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vvi res;
        if(!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> tmp;
            for(int i = 0;i<sz;i++)
            {
                TreeNode *p = q.front();
                q.pop();
                tmp.push_back(p->val);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            res.push_back(tmp);
        }
        
        return res;
    }
};