class Solution {
public:
    int f(int i,int j,vector<vector<int>> &triangle,vector<vector<int>> &dp)
    {
        if(i==triangle.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int v1 = f(i+1,j,triangle,dp);
        int v2 = f(i+1,j+1,triangle,dp);
        return dp[i][j] = triangle[i][j] + min(v1,v2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        return f(0,0,triangle,dp);
    }
};