class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
            sum+=nums[i];
        if(sum%2)
            return false;
        sum/=2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));
        for(int i = 0;i<=n;i++)
        {
            for(int j = 0;j<=sum;j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
                if(i>0 and nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
                else if(i>0 and nums[i-1]>j)
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};