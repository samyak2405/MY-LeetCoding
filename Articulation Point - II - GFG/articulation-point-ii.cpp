// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    void dfs(int node,int parent,vector<int> adj[],vector<int> &low,vector<int> &disc,
        vector<bool> &vis,vector<bool> &isAP,int &timer)
        {
            int child = 0;
            low[node] = disc[node] = timer++;
            vis[node] = true;
            for(auto it:adj[node])
            {
                if(it==parent)
                    continue;
                if(!vis[it])
                {
                    child++;
                    dfs(it,node,adj,low,disc,vis,isAP,timer);
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
        vector<bool> isAP(V,0),vis(V,0);
        vector<int> disc(V,0),low(V,0);
        for(int i = 0;i<V;i++)
        {
            int timer = 0;
            if(!vis[i])
                dfs(i,-1,adj,low,disc,vis,isAP,timer);
        }
        for(int i = 0;i<V;i++)
            if(isAP[i]==1)
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