class Solution {
public:
    
    
    int dfs(int r,int c,int m,int n,int prev,vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
        if(r<0 or c<0 or r==m or c==n or matrix[r][c]<=prev)
            return 0;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int v1 = dfs(r-1,c,m,n,matrix[r][c],matrix,dp);
        int v2 = dfs(r+1,c,m,n,matrix[r][c],matrix,dp);
        int v3 = dfs(r,c-1,m,n,matrix[r][c],matrix,dp);
        int v4 = dfs(r,c+1,m,n,matrix[r][c],matrix,dp);
        return dp[r][c] = 1+max(v1,max(v2,max(v3,v4)));
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                dfs(i,j,m,n,-1,matrix,dp);
        int ans = 0;
        for(int i= 0;i<m;i++)
            for(int j = 0;j<n;j++)
                ans = max(ans,dp[i][j]);
        return ans;
    }
};