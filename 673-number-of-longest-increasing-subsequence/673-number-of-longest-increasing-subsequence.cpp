class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {
            for(int prev = 0;prev<i;prev++)
            {
                if(arr[prev]<arr[i] and 1+dp[prev]>dp[i])
                {
                    dp[i] = 1+dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(arr[prev]<arr[i] and 1+dp[prev]==dp[i])
                {
                    cnt[i] +=cnt[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++)
            if(maxi==dp[i])
                ans+=cnt[i];
        return ans;
    }
};