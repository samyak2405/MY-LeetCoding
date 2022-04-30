// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[],vector<bool> &vis1,vector<bool> &vis2,int start)
    {
        vis1[start] = true;
        vis2[start] = true;
        
        for(auto it:adj[start])
        {
            if(!vis1[it])
            {
                if(dfs(adj,vis1,vis2,it))
                    return true;
            }
            else if(vis2[it])
                return true;
        }
        
        vis2[start] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis1(V,0),vis2(V,0);
        
        for(int i = 0;i<V;i++)
        {
            if(!vis1[i])
                if(dfs(adj,vis1,vis2,i))
                    return true;
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends