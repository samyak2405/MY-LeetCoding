class Solution {
    vector<vector<int>> res;
    vector<int> disc;
    vector<int> low;
    vector<bool> vis;
    map<int,vector<int>> mp;
    int timer;
public:
    
    void dfs(vector<vector<int>> &conn,int node,int parent)
    {
        vis[node] = true;
        low[node] =disc[node] = timer++;
        for(auto it:mp[node])
        {
            if(it==parent)
                continue;
            if(!vis[it])
            {
                dfs(conn,it,node);
                low[node] = min(low[node],low[it]);
                if(low[it]>disc[node])
                    res.push_back({it,node});
            }
            else
                low[node] = min(low[node],disc[it]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        disc.resize(n,0);
        low.resize(n,0);
        vis.resize(n,0);
        for(auto it:conn)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        timer = 0;
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
                dfs(conn,i,-1);
        }
        return res;
    }
};