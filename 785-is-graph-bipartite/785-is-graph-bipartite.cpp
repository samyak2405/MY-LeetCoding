class Solution {
public:
    
    bool bipartite(map<int,vector<int>> &mp,vector<int> &color,int start)
    {
        for(auto it:mp[start])
        {
            if(color[it]==-1)
            {
                color[it] = 1-color[start];
                if(!bipartite(mp,color,it))
                    return false;
            }
            else if(color[it]==color[start])
                return false;
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
                color[i] = 1;
                if(!bipartite(mp,color,i))
                    return false;
            }
        }
        return true;
    }
};