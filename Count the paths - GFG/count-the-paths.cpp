// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    int dfs(map<int,vector<int>> &mp,vector<bool> &vis,int s,int d)
    {
        if(s == d)
            return 1;
        vis[s] = true;
        int ans = 0;
        for(auto it:mp[s])
        {
            if(!vis[it])
                ans+= dfs(mp,vis,it,d);
        }
        vis[s] = false;
        return ans;
    }

	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    map<int,vector<int>> mp;
	    for(int i = 0;i<edges.size();i++)
	        mp[edges[i][0]].push_back(edges[i][1]);
	    vector<bool> vis(n,false);
	    return dfs(mp,vis,s,d);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends