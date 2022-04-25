class Solution {
public:
    
    int f(int i,int j,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
        if(i==n-1)
            return matrix[n-1][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int left = INT_MAX,right = INT_MAX,mid = INT_MAX;
        if(j-1>=0)
            left = matrix[i][j] + f(i+1,j-1,n,matrix,dp);
        if(j>=0)
            right = matrix[i][j] + f(i+1,j,n,matrix,dp);
        if(j+1<n)
            mid = matrix[i][j] + f(i+1,j+1,n,matrix,dp);
        return dp[i][j] = min(left,min(right,mid));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i = 0;i<n;i++)
            mini = min(mini,f(0,i,n,matrix,dp));
        return mini;
    }
};