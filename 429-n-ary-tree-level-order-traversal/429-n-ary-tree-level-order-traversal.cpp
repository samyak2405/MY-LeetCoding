/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> tmp;
            
            for(int i = 0;i<sz;i++)
            {
                Node *p = q.front();
                q.pop();
                tmp.push_back(p->val);
                for(int i = 0;i<p->children.size();i++)
                {
                    q.push(p->children[i]);
                }
            }
            res.push_back(tmp);
        }
        
        return res;
    }
};