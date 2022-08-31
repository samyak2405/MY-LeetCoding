class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        for(auto it:nums)
            target+=it;
        int n = nums.size();
        if(target==0)
            return n;
        int res = INT_MIN;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i = 0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum-target)!=mp.end())
                res = max(res,i-mp[sum-target]);
            mp[sum] = i;
        }
        return res == INT_MIN?-1:n-res;
    }
};