class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        
        for(int i = 0;i<=k;i++)
        {
            vector<int> tmp(dist);
            
            for(auto it:flights)
            {
                if(dist[it[0]]!=INT_MAX)
                    tmp[it[1]] = min(tmp[it[1]],dist[it[0]]+it[2]);
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX?-1:dist[dst];
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        //Using BFS:TLE
//         unordered_map<int,vector<pair<int,int>>> adj;
//         for(auto it:flights)
//             adj[it[0]].push_back({it[1],it[2]});
//         queue<pair<int,int>> q;
//         q.push({src,0});
//         int stod = INT_MAX;
        
//         while(!q.empty() and k-->=0)
//         {
//             int sz = q.size();
//             for(int i = 0;i<sz;i++)
//             {
//                 int u = q.front().first;
//                 int w = q.front().second;
//                 q.pop();
//                 for(auto it:adj[u])
//                 {
//                     if(stod<w+it.second)
//                         continue;
//                     q.push({it.first,w+it.second});
//                     if(dst==it.first)
//                         stod = min(stod,w+it.second);
//                 }
//             }
//         }
//         return stod==INT_MAX?-1:stod;
    }
};