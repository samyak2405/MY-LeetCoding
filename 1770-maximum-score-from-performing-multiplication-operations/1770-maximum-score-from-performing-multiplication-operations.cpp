class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int l,int n,vector<int> &nums,vector<int> &multipliers)
    {
        if(i==multipliers.size())
            return 0;
        if(dp[l][i]!=INT_MIN)
            return dp[l][i];
        int left = multipliers[i]*nums[l]+f(i+1,l+1,n,nums,multipliers);
        int right = multipliers[i]*nums[(n - 1) - (i - l)]+f(i+1,l,n,nums,multipliers);
        return dp[l][i] = max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return f(0,0,n,nums,multipliers);
    }
};