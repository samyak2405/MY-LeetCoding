// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void dfs(map<int,vector<int>> &mp,int s,int d,int &cnt)
    {
        if(s == d)
            cnt++;
        for(auto it:mp[s])
        {
            dfs(mp,it,d,cnt);
        }
        return;
    }

	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    int cnt = 0;
	    map<int,vector<int>> mp;
	    for(int i = 0;i<edges.size();i++)
	        mp[edges[i][0]].push_back(edges[i][1]);
	    dfs(mp,s,d,cnt);
	    return cnt;
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