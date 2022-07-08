// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    #define vvi vector<vector<int>>
    #define map map<int,vector<pair<int,int>>>
    #define vi vector<int> 
    #define vb vector<bool>
    void topologySort(vector<int> &src,int node,map &mp,vb &vis)
    {
        vis[node] = true;
        for(auto it:mp[node])
        {
            if(!vis[it.first])
                topologySort(src,it.first,mp,vis);
        }
        src.push_back(node);
    }
    
    void dijkstra(map &mp,vi &src,int n,int srce,vi &dist)
    {
        for(int source = src.size()-1;source>=0;source--)
        {
            int node = src[source];
            if(dist[node]!=INT_MIN)
            {
                for(auto it:mp[node])
                {
                    if(dist[node]+it.second>dist[it.first])
                        dist[it.first] = dist[node] + it.second;
                }
            }
        }
        return;
    }
    
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int srce)
      {
            map mp;
            for(auto it:edges)
                mp[it[0]].push_back({it[1],it[2]});
            
            vi src;
            vb vis(v,false);
            topologySort(src,srce,mp,vis);
            vi res(v,INT_MIN);
            res[srce] = 0;
            dijkstra(mp,src,v,srce,res);
            return res;
      }
};

// { Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}  // } Driver Code Ends