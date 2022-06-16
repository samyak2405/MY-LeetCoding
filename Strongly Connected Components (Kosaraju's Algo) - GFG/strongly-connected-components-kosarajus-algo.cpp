// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void topologicalSort(vector<int> adj[],int start,vector<bool> &vis,stack<int> &s1)
	{
	    vis[start] = true;
	    for(auto it:adj[start])
	    {
	        if(!vis[it])
	            topologicalSort(adj,it,vis,s1);
	    }
	    s1.push(start);
	}
	
	void dfs(vector<vector<int>> &mp,int start,vector<bool> &vis)
	{
	    vis[start] = true;
	    for(auto it:mp[start])
	    {
	        if(!vis[it])
	            dfs(mp,it,vis);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> s1;
        vector<bool> vis(V,false);
        for(int i = 0;i<V;i++){
            if(!vis[i])
                topologicalSort(adj,i,vis,s1);
        }
        vector<vector<int>> mp(V);
        for(int i = 0;i<V;i++){
            vis[i] = false;
            for(auto it:adj[i])
                mp[it].push_back(i);
        }
        
        int cnt = 0;
        while(!s1.empty())
        {
            int node =s1.top();
            s1.pop();
            if(!vis[node])
            {
                dfs(mp,node,vis);
                cnt++;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends