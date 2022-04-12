class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        int maxim = 0;
        for(int i :nums)
            maxim = max(maxim,i);
        int dp[maxim+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<nums.size();i++)
            dp[nums[i]]++;
        int inc = 0;
        int exc = 0;
        for(int i = 0;i<maxim+1;i++)
        {
            int new_inc = exc + dp[i]*i;
            int new_exc = max(inc,exc);
            
            inc = new_inc;
            exc = new_exc;
        }
        return max(inc,exc);
    }
};