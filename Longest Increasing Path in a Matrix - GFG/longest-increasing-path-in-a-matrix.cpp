// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dfs(int r,int c,int prev,int m,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
        if(r<0 or c<0 or r==m or c==n or prev>=matrix[r][c])
            return 0;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int v1 = dfs(r-1,c,matrix[r][c],m,n,matrix,dp);
        int v2 = dfs(r+1,c,matrix[r][c],m,n,matrix,dp);
        int v3 = dfs(r,c-1,matrix[r][c],m,n,matrix,dp);
        int v4 = dfs(r,c+1,matrix[r][c],m,n,matrix,dp);
        return dp[r][c] = 1+max(v1,max(v2,max(v3,v4)));
    }
  
    int longestIncreasingPath(vector<vector<int>>& matrix, int m, int n) {
        int ans = 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                dfs(i,j,-1,m,n,matrix,dp);
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends