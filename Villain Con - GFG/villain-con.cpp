// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int n, int M, vector<int> mat[]) {
        vector<int> indegree(n+1,0);
        map<int,vector<int>> mp;
        for(int i = 0;i<M;i++)
            mp[mat[i][1]].push_back(mat[i][0]);
        for(int i = 0;i<M;i++)
            indegree[mat[i][0]]++;
        queue<int> q;
        for(int i = 1;i<n+1;i++)
            if(indegree[i]==0)
                q.push(i);
        if(q.empty())
            return 0;
        int cnt = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0;i<sz;i++)
            {
                int node = q.front();
                q.pop();
                for(auto it:mp[node])
                {
                    indegree[it]--;
                    if(indegree[it]==0)
                        q.push(it);
                }
            }
            cnt++;
            
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends