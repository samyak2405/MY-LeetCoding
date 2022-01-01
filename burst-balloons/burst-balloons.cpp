class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> inums;
        inums.emplace_back(1);
        for(auto it:nums)
            inums.emplace_back(it);
        inums.emplace_back(1);
        int n = inums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int k = 2;k<n;k++)
        {
            for(int left = 0;left<n-k;left++)
            {
                int right = left + k;
                for(int i = left +1;i<right;i++)
                {
                    dp[left][right] = max(dp[left][right],
                                          inums[left]*inums[i]*inums[right]
                                          + dp[left][i] 
                                          + dp[i][right]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};