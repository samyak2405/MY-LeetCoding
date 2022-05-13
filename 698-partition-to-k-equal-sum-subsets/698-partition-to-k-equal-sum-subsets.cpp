class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i:nums)
            sum+=i;
        if(sum%k)
            return false;
        int n = nums.size();
        if(n<k)
            return false;
        sum/=k;
        int dp[(1<<16)+2];
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for(int mask = 0;mask<(1<<n);mask++)
        {
            if(dp[mask]==-1)
                continue;
            for(int i = 0;i<n;i++)
            {
                if(!(mask&(1<<i)) and dp[mask]+nums[i]<=sum)
                {
                    dp[mask|(1<<i)] = (dp[mask]+nums[i])%sum;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};