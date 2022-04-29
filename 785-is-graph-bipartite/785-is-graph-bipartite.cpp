class Solution {
public:
    
    bool bipartite(map<int,vector<int>> &mp,vector<int> &color,int start)
    {
        queue<int> q;
        q.push(start);
        color[start] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:mp[node])
            {
                if(color[it]==-1)
                {
                    color[it] = 1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        map<int,vector<int>> mp;
        int n = graph.size();
        for(int i = 0;i<n;i++)
            mp[i] = graph[i];
        vector<int> color(n,-1);
        for(int i = 0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartite(mp,color,i))
                    return false;
            }
        }
        return true;
    }
};