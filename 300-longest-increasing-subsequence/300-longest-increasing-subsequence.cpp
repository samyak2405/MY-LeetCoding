class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1),hash(nums.size());
        int maxi = INT_MIN;
        int lastind = 0;
        for(int i = 0;i<nums.size();i++)
        {
            hash[i] =i;
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i] and dp[i]<1+dp[j])
                {
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(maxi<dp[i])
            {
                maxi = dp[i];
                lastind = i;
            }
        }
        vector<int> lis;
        lis.push_back(nums[lastind]);
        while(hash[lastind]!=lastind)
        {
            lastind = hash[lastind];
            lis.push_back(nums[lastind]);
        }
        reverse(lis.begin(),lis.end());
        for(auto it:lis)
            cout<<it<<" ";
        return maxi;
    }
};