class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        if(nums[l]<=nums[r])
            return nums[l];
        while(l<r and nums[l]>=nums[r])
        {
            int mid = l+(r-l)/2;
            if(nums[mid]>nums[r])
                l = mid+1;
            else if(nums[mid]<nums[l])
            {
                r = mid;
                l++;
            }
            else
                r--;
        }
        return nums[l];
    }
};