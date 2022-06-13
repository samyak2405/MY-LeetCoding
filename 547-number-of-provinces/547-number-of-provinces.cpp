class Solution {
public:
    
    int find(vector<int> &parent,int x)
    {
        if(parent[x]==x)
            return x;
        parent[x] = find(parent,parent[x]);
        return parent[x];
    }
    
    void _union(vector<int> &parent,int x,int y)
    {
        int x_rep = find(parent,x);
        int y_rep = find(parent,y);
        if(x_rep==y_rep)
            return;
        parent[y_rep] = x_rep;
    }
    
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> parent(n);
        for(int i = 0;i<n;i++)
            parent[i] = i;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
                if(mat[i][j])
                    _union(parent,i,j);
        }
        set<int> s1;
        
        for(int i = 0;i<n;i++)
            s1.insert(find(parent,parent[i]));
        return s1.size();
    }
};