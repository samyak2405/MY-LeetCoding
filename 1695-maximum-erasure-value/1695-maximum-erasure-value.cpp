class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s1;
        int n = nums.size();
        for(int i = 0,j=0,win=0;j<n;j++)
        {
            while(s1.find(nums[j])!=s1.end())
            {
                s1.erase(nums[i]);
                win-=nums[i];
                i++;
            }
            s1.insert(nums[j]);
            win += nums[j];
            res = max(res,win);
        }
        return res;
    }
};