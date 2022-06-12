class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        for(auto it:nums)
            target+=it;
        if(target==0)
            return nums.size();
        int res = INT_MIN;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum-target)!=mp.end())
            {
                res = max(res,i-mp[sum-target]);
            }
            mp[sum] = i;
        }
        return res==INT_MIN?-1:nums.size()-res;
    }
};