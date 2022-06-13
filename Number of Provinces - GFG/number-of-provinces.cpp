// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int find(vector<int> &parent,int x)
    {
        if(parent[x]==x)
            return x;
        parent[x]=find(parent,parent[x]);
        return parent[x];
    }
  
    void _union(vector<int> &parent,int x,int y)
    {
        int x_rep = find(parent,x);
        int y_rep = find(parent,y);
        if(x_rep == y_rep)
            return;
        parent[y_rep] = x_rep;
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> parent(V);
        for(int i = 0;i<V;i++)
            parent[i] = i;
        for(int i = 0;i<V;i++)
        {
            for(int j = 0;j<V;j++)
            {
                if(adj[i][j])
                    _union(parent,i,j);
            }
        }
        set<int> s1;
        for(int i = 0;i<V;i++)
            s1.insert(find(parent,parent[i]));
        return s1.size();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends