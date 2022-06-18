// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    
    void dfs(vector<int> adj[],vector<bool> &vis,int src,int dest,int &cnt)
    {
        if(src==dest)
            cnt++;
        vis[src]=true;
        for(auto it:adj[src])
        {
            if(!vis[it])
                dfs(adj,vis,it,dest,cnt);
        }
        vis[src] = false;
    }
    
    int countPaths(int V, vector<int> adj[], int src, int dest) {
        vector<bool> vis(V,false);
        int cnt = 0;
        dfs(adj,vis,src,dest,cnt);
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends