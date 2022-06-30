class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long mid = nums[n/2];
        long long diff = 0;
        for(int i = 0;i<nums.size();i++)
        {
            diff+=abs(nums[i]-mid);
        }
        return diff;
    }
};