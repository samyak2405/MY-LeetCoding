class Solution {
public:
    
    int find(vector<int> &parent,int x)
    {
        if(parent[x]==x)
            return x;
        parent[x] = find(parent,parent[x]);
        return parent[x];
    }
    
    bool _union(vector<int> &parent,int x,int y)
    {
        int x_rep = find(parent,x);
        int y_rep = find(parent,y);
        if(x_rep==y_rep)
            return true;
        parent[y_rep] = x_rep;
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2);
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1;i<n+1;i++)
            parent[i] = i;
        for(int i = 0;i<n;i++)
        {
            if(_union(parent,edges[i][0],edges[i][1]))
            {
                res[0] = edges[i][0];
                res[1] = edges[i][1];
            }
        }
        
        return res;
    }
};