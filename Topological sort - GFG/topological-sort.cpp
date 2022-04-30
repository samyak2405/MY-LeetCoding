// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	
	bool dfs(vector<int> adj[],vector<bool> &vis,int start,stack<int> &s1)
	{
	    vis[start] =true;
	    for(auto it:adj[start])
	    {
	        if(!vis[it])
	        {
	            dfs(adj,vis,it,s1);
	        }
	    }
	    s1.push(start);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> res;
	    stack<int> s1;
	    vector<bool> vis(V,0);
	    for(int i = 0;i<V;i++)
	    {
	        if(!vis[i])
	            dfs(adj,vis,i,s1);
	    }
	    
	    while(!s1.empty())
	    {
	        res.push_back(s1.top());
	        s1.pop();
	    }
	    return res;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends