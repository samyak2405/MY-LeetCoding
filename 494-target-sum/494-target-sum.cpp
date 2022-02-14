class Solution {
public:
    
    int subset_sum(vector<int> &nums,int target)
    {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(target+1));
        
        for(int i = 0;i<target+1;i++)
            dp[0][i] = 0;
        dp[0][0] = 1;
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 0;j<target+1;j++)
            {
                if(nums[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        if(!nums.size())
            return 0;
        int sum = 0;
        for(auto it:nums)
        {
            sum+=it;
        }
        if(abs(target)>sum or (target+sum)%2!=0)
            return 0;
        
        int sum1 = (sum+target)/2;
        return subset_sum(nums,sum1);
    }
};