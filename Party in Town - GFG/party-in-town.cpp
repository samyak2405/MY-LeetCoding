// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void dfs(vector<vector<int>> &mp,vector<int> &dist,int i,int prev)
    {
        for(auto it:mp[i])
        {
            if(prev==it)
                continue;
            dist[it] = 1+dist[i];
            dfs(mp,dist,it,i);
        }
    }
    
    int partyHouse(int N, vector<vector<int>> &adj){
        int d = INT_MAX;
        for(int i = 1;i<=N;i++)
        {
            vector<int> dist(N+1);
            dfs(adj,dist,i,0);
            int mn = 0;
            for(int j =1;j<=N;j++)
                mn = max(mn,dist[j]);
            d = min(d,mn);
        }
        return d;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends