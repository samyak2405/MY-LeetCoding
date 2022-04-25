class Solution {
public:
    
//     int f(int i,int j,int n,vector<vector<int>> &triangle,vector<vector<int>> &dp)
//     {
//         if(i==n-1)
//             return triangle[n-1][j];
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         return dp[i][j] = triangle[i][j] + min(f(i+1,j,n,triangle,dp),f(i+1,j+1,n,triangle,dp));
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return f(0,0,n,triangle,dp);
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0;i<m;i++)
            dp[m-1][i] = triangle[m-1][i];
        for(int i = n-2;i>=0;i--)
        {
            for(int j = i;j>=0;j--)
            {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};