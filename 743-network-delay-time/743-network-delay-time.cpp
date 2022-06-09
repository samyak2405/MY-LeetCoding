class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e8);
        dist[k] = 0;
        
        for(int i = 0;i<n-1;i++)
        {
            for(auto it:times)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if(dist[v]>dist[u]+w)
                    dist[v] = dist[u]+w;
            }
        }
        
        int time = 0;
        for(int i = 1;i<n+1;i++)
        {
            if(dist[i]==1e8)
                return -1;
            time = max(time,dist[i]);
        }
        return time;
    }
};