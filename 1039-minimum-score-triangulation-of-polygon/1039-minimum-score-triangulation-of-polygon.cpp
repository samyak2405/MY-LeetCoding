class Solution {
public:
    #define vvi vector<vector<int>>
    // int f(int i,int j,vector<int> &nums,vvi &dp)
    // {
    //     if(i+1==j)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int ans = INT_MAX;
    //     for(int k = i+1;k<j;k++)
    //     {
    //         int tmp = nums[i]*nums[k]*nums[j] + f(i,k,nums,dp)+f(k,j,nums,dp);
    //         ans = min(ans,tmp);
    //     }
    //     return dp[i][j] = ans;
    // }
    
    int minScoreTriangulation(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return f(0,n-1,nums,dp);
        vvi dp(n,vector<int>(n,0));
        for(int i = n-1;i>=0;i--)
        {
            for(int j = i+2;j<n;j++)
            {
                int ans = INT_MAX;
                for(int k=i+1;k<j;k++)
                    ans = min(ans,nums[i]*nums[j]*nums[k]+dp[i][k]+dp[k][j]);
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
};