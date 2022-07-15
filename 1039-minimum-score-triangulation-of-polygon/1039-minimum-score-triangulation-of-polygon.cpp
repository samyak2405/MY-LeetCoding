class Solution {
public:
    #define vvi vector<vector<int>>
    int f(int i,int j,vector<int> &nums,vvi &dp)
    {
        if(i+1==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1;k<j;k++)
        {
            int tmp = nums[i]*nums[k]*nums[j] + f(i,k,nums,dp)+f(k,j,nums,dp);
            ans = min(ans,tmp);
        }
        return dp[i][j] = ans;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,n-1,values,dp);
    }
};