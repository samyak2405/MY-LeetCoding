class Solution {
public:
    
    int find(vector<int> &parent,int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent,parent[x]);
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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        for(int i = 0;i<parent.size();i++)
            parent[i] = i;
        int cnt = 0;
        for(auto it:connections)
            if(_union(parent,it[0],it[1]))
                cnt++;
        cout<<cnt<<endl;
        set<int> s1;
        for(int i = 0;i<parent.size();i++)
        {
            int x = find(parent,parent[i]);
            s1.insert(x);
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<s1.size()<<" ";
        if(cnt>=s1.size()-1)
            return s1.size()-1;
        return -1;
    }
};