// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(vector<int> adj[],vector<int> &res,vector<bool> &vis,int start)
    {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it] = true;
                }    
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        if(V==0)
            return res;
        vector<bool> vis(V,0);
        int start = 0;
        queue<int> q;
        q.push(start);
        vis[start] = true;
        for(int i = 0;i<V;i++)
        {
            // if(!vis[i])
            //     bfs(adj,res,vis,i);
            if(!vis[i])
            {
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    res.push_back(node);
                    for(auto it:adj[node])
                    {
                        if(!vis[it])
                        {
                            q.push(it);
                            vis[it] = true;
                        }    
                    }
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends