class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MAX;
        for(int i = 0;i<nums.size();i++)
            maxi = min(maxi,nums[i]);
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
            ans += abs(nums[i]-maxi);
        return ans;
    }
};