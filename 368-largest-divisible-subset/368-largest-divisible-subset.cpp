class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int lastind = 0;
        int maxi = 1;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        for(int i = 0;i<n;i++)
        {
            hash[i] = i;
            for(int prev = 0;prev<i;prev++)
            {
                if((nums[i]%nums[prev]==0 or nums[prev]%nums[i]==0) and 1+dp[prev]>dp[i])
                {
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(maxi<dp[i])
            {
                maxi = dp[i];
                lastind = i;
            }
        }
        
        vector<int> res;
        res.push_back(nums[lastind]);
        
        while(hash[lastind]!=lastind)
        {
            lastind = hash[lastind];
            res.push_back(nums[lastind]);
        }
        
        return res;
    }
};