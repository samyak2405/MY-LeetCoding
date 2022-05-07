// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int i,int j,int n,int m,vector<vector<int>> &mine,vector<vector<int>> &dp)
    {
        if(i<0 or j<0 or i>=n or j>=m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int v1 = f(i-1,j+1,n,m,mine,dp);
        int v2 = f(i,j+1,n,m,mine,dp);
        int v3 = f(i+1,j+1,n,m,mine,dp);
        return dp[i][j] = mine[i][j] + max(v1,max(v2,v3));
    }

    int maxGold(int n, int m, vector<vector<int>> &mine)
    {
        int res = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++)
            res = max(res,f(i,0,n,m,mine,dp));
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends