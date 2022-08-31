class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        int j = 0;
        unordered_set<int> s1;
        int win = 0;
        for(int i = 0;i<n;i++)
        {
            while(s1.find(nums[i])!=s1.end())
            {
                s1.erase(nums[j]);
                win-= nums[j];
                j++;
            }
            s1.insert(nums[i]);
            win+=nums[i];
            res = max(res,win);
        }
        return res;
    }
};