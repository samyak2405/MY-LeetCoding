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
class BSTIterator {
public:
    vector<int> res;
    int i = 0;
    BSTIterator(TreeNode* root) {
        stack<TreeNode *> s1;
        while(root or !s1.empty())
        {
            while(root)
            {
                s1.push(root);
                root = root->left;
            }
            root = s1.top();
            s1.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }
    
    int next() {
        int x = res[i];
        i++;
        return x;
    }
    
    bool hasNext() {
        return i<res.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */