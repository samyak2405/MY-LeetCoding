// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int node,int parent,vector<int> adj[],vector<bool> &vis,vector<int> &res,vector<int> &low,vector<int> &disc,int &timer)
    {
        int child = 0;
        vis[node] = true;
        low[node] = disc[node] = timer++;
        
        for(auto it:adj[node])
        {
            if(it==parent)
                continue;
            if(!vis[it])
            {
                dfs(it,node,adj,vis,res,low,disc,timer);
                low[node] = min(low[node],low[it]);
                if(low[it]>=disc[node] and parent!=-1)
                    res[node] = 1;
                child++;
            }
            else
            {
                low[node] = min(low[node],disc[it]);
            }
        }
        if(parent==-1 and child>1)
            res[node] = 1;
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> res;
        vector<bool> vis(V,false);
        vector<int> low(V,0), disc(V,0),isArticulation(V,0);
        int timer = 0;
        dfs(0,-1,adj,vis,isArticulation,low,disc,timer);
        for(int i = 0;i<V;i++)
            if(isArticulation[i]==1)
                res.push_back(i);
        if(res.size()==0)
            return {-1};
        return res;
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
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends