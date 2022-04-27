class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return 0;
        vector<int> dp1(n,1),dp2(n,1);
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {
            for(int prev =0;prev<i;prev++)
            {
                if(nums[prev]<nums[i] and 1+dp1[prev]>dp1[i])
                    dp1[i] = 1+dp1[prev];
            }
        }
        for(int i = n-1;i>=0;i--)
        {
            for(int prev = n-1;prev>i;prev--)
            {
                if(nums[prev]<nums[i] and 1+dp2[prev]>dp2[i])
                    dp2[i] = 1+dp2[prev];
            }
        }
        for(int i = 0;i<n;i++)
        {
            if(dp1[i]>1 and dp2[i]>1)
            maxi = max(maxi,dp1[i]+dp2[i]-1);
        }
        return n-maxi;
    }
};