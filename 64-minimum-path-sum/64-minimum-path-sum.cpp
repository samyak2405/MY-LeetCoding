class Solution {
public:
    
    // int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
    // {
    //     if(i==0 and j==0)
    //         return grid[0][0];
    //     if(i<0 or j<0)
    //         return INT_MAX;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     return dp[i][j] = grid[i][j] + min(f(i-1,j,grid,dp),f(i,j-1,grid,dp));
    // }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,grid,dp);
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
//         for(int i = 0;i<m+1;i++)
//         {
//             for(int j = 0;j<n+1;j++)
//             {
//                 if(i==0 or j==0)
//                     dp[i][j] = INT_MAX;
//                 else if(i==1 and j==1)
//                     dp[i][j] = grid[i-1][j-1];
//                 else
//                 {
//                     int up = 0,left = 0;
//                     if(i>0 and j>=0)
//                         up = dp[i-1][j];
//                     if(j>0 and i>=0)
//                         left = dp[i][j-1];
//                     dp[i][j] = grid[i-1][j-1]+min(up,left);
//                 }
//             }
//         }
        
//         return dp[m][n];
        vector<int>prev(n+1,0);
        for(int i = 0;i<m+1;i++)
        {
            vector<int> curr(n+1,0);
            for(int j = 0;j<n+1;j++)
            {
                if(i==0 or j==0)
                    prev[j] = curr[j] = INT_MAX;
                else if(i==1 and j==1)
                    curr[j] = grid[i-1][j-1];
                else
                {
                    int left = 0,up = 0;
                    if(i>0 and j>=0)
                        up = prev[j];
                    if(j>0 and i>=0)
                        left = curr[j-1];
                    curr[j] = grid[i-1][j-1]+min(up,left);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};