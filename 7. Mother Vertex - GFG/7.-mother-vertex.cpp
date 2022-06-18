// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int start,vector<bool> &vis,vector<int> adj[])
    {
        vis[start] = true;
        for(auto it:adj[start])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int mv = 0;
	    vector<bool> vis(V,false);
	    for(int i = 0;i<V;i++){
	        if(!vis[i])
	       {
	               dfs(i,vis,adj);
	               mv = i;
	        }
	    }
	    fill(vis.begin(),vis.end(),false);
	    dfs(mv,vis,adj);
	    for(int i = 0;i<V;i++)
	    {
	        if(!vis[i])
	            return -1;
	    }
	    return mv;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends