class Solution {
public:
    
    int f(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i==m or j==n)
            return 1e9;
        if(i==m-1 and j==n-1)
            return dp[i][j] = grid[i][j]>=0?1:1-grid[i][j];
        int up = f(i+1,j,m,n,grid,dp);
        int down = f(i,j+1,m,n,grid,dp);
        int ans = min(up,down)-grid[i][j];
        return dp[i][j] = ans<=0?1:ans;
    }
    
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return f(0,0,m,n,grid,dp);
        vector<vector<int>> dp(m+1,vector<int>(n+1,1e9));
        dp[m][n-1] = 1;
        dp[m-1][n] = 1;
        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                int ans = min(dp[i+1][j],dp[i][j+1])-grid[i][j];
                dp[i][j] = ans<=0?1:ans;
            }
        }
        return dp[0][0];
    }
};