// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    int dfs(int i,int j,int n,int m,int prev,vector<vector<int>> &dp,vector<vector<int>> &matrix)
    {
        if(i<0 or j<0 or i==n or j==m or matrix[i][j]<=prev)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int v1 = dfs(i-1,j,n,m,matrix[i][j],dp,matrix);
        int v2 = dfs(i+1,j,n,m,matrix[i][j],dp,matrix);
        int v3 = dfs(i,j-1,n,m,matrix[i][j],dp,matrix);
        int v4 = dfs(i,j+1,n,m,matrix[i][j],dp,matrix);
        return dp[i][j] = 1+max(v1,max(v2,max(v3,v4)));
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                ans = max(ans,dfs(i,j,n,m,-1,dp,matrix));
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends