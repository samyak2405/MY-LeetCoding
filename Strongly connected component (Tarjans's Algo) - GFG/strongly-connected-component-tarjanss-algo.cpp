// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    vector<vector<int>> res;
    vector<int> disc;
    vector<int> low;
    stack<int> st;
    vector<bool> stkmem;
    int  timer = 0;
	public:
	
    void dfs(int start,vector<int> adj[])
    {
        disc[start] = low[start] = timer++;
        st.push(start);
        stkmem[start] = 1;
        for(auto it:adj[start])
        {
            if(disc[it]==-1)
            {
                dfs(it,adj);
                low[start] = min(low[start],low[it]);
            }
            else if(stkmem[it])
                low[start] = min(low[start],disc[it]);
        }
        vector<int> tmp;
        if(low[start]==disc[start])
        {
            int num = st.top();
            while(st.top()!=start)
            {
                int num = st.top();
                tmp.push_back(num);
                stkmem[num] = false;
                st.pop();
            }
            tmp.push_back(st.top());
            res.push_back(tmp);
            stkmem[st.top()] = false;
            st.pop();
        }
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        disc.resize(V,-1);
        low.resize(V,-1);
        stkmem.resize(V,false);
        for(int i = 0;i<V;i++)
            if(disc[i]==-1)
                dfs(i,adj);
        for(auto &it:res)
            sort(it.begin(),it.end());
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends