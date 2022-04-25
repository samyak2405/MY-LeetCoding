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
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return f(0,0,n,triangle,dp);
        // vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> ahead(n,0),curr(n,0);
        for(int i = 0;i<n;i++)
            ahead[i] = triangle[n-1][i];
        for(int i = n-2;i>=0;i--)
        {
            for(int j = i;j>=0;j--)
                curr[j] = triangle[i][j] + min(ahead[j],ahead[j+1]);
            ahead = curr;
        }
        return ahead[0];
    }
};