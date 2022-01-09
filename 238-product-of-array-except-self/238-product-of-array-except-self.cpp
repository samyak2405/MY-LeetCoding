class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1,right = 1;
        vector<int> res(nums.size());
        res[0] = 1;
        for(int i = 1;i<nums.size();i++)
            res[i] = left *= nums[i-1];
        for(int i = nums.size()-2;i>=0;i--)
            res[i]*= right *= nums[i+1];
        
        return res;
    }
};