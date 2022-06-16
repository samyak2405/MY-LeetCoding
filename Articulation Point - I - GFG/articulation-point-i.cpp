// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int node,int parent,vector<int> adj[],vector<int> &disc,vector<int> &low,vector<bool> &isAP,vector<bool> &vis,int &timer)
    {
        low[node] = disc[node] = timer++;
        vis[node] = true;
        int child = 0;
        
        for(auto it:adj[node])
        {
            if(it==parent)
                continue;
            if(!vis[it])
            {
                child++;
                dfs(it,node,adj,disc,low,isAP,vis,timer);
                low[node] = min(low[node],low[it]);
                if(low[it]>=disc[node] and parent!=-1)
                    isAP[node] = 1;
            }
            else
                low[node] = min(low[node],disc[it]);
        }
        
        if(parent==-1 and child>1)
            isAP[node] = 1;
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> res;
        vector<int> disc(V,0),low(V,0);
        vector<bool> isAP(V,false),vis(V,false);
        int timer = 0;
        dfs(0,-1,adj,disc,low,isAP,vis,timer);
        for(int i = 0;i<V;i++)
            if(isAP[i])
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