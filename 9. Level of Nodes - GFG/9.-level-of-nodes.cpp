// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int levelOfX(int V, vector<int> adj[], int X) {
	    queue<int> q;
	    q.push(0);
	    vector<bool> vis(V,false);
	    int cnt = 0;
	    while(!q.empty())
	    {
	        int sz = q.size();
	        for(int i =0;i<sz;i++)
	        {
	            int node = q.front();
	            q.pop();
	            if(node==X)
	                return cnt;
	            for(auto it:adj[node])
	            {
	                if(!vis[it])
	                    q.push(it);
	            }
	        }
	        cnt++;
	        
	    }
	    return -1;
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
        int X;
        cin >> X;
        Solution obj;
        cout<<obj.levelOfX(V,adj,X)<<endl;
	}
	return 0;
}  // } Driver Code Ends