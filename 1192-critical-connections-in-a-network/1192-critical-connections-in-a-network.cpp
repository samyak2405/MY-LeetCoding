class Solution {
public:
    
    void dfs(int node,int parent,vector<bool> &vis,vector<int> &tin,vector<int> &low,int &timer,map<int,vector<int>> &mp,vector<vector<int>> &res)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto it:mp[node])
        {
            if(it==parent)
                continue;
            if(!vis[it])
            {
                dfs(it,node,vis,tin,low,timer,mp,res);
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node])
                {
                    vector<int> tmp;
                    tmp.push_back(it);
                    tmp.push_back(node);
                    res.push_back(tmp);
                }
            }
            else
                low[node] = min(low[node],tin[it]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        map<int,vector<int>> mp;
        for(int i = 0;i<connections.size();i++)
        {
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> vis(n,0);
        vector<int> tin(n,-1),low(n,-1);
        int timer = 0;
        for(int i = 0;i<n;i++)
            if(!vis[i])
                dfs(i,-1,vis,tin,low,timer,mp,res);
        return res;
    }
};