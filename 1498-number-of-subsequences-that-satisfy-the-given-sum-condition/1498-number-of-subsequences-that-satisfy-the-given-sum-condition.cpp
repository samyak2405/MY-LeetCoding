class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0;
        int mod = 1e9+7;
        int n = nums.size();
        int l = 0,r = n-1;
        sort(nums.begin(),nums.end());
        vector<int> pows(n,1);
        for(int i =1;i<n;i++)
            pows[i] = (pows[i-1]*2)%mod;
        while(l<=r)
        {
            if(nums[l]+nums[r]>target)
                r--;
            else
                res = (res+pows[r-l++])%mod;
        }
        return res;
    }
};