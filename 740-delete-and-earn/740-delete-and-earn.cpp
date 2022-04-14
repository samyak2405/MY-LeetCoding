class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m = 0;
        for(int i :nums)
            m = max(m,i);
        int dp[m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<nums.size();i++)
            dp[nums[i]]+=nums[i];
        int take = 0,skip = 0;
        for(int i = 0;i<m+1;i++)
        {
            int takei = dp[i] + skip;
            int skipi = max(skip,take);
            take = takei;
            skip = skipi;
        }
        return max(take,skip);
    }
};