class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0,j = nums.size()-1;
        if(nums[i]<nums[j])
            return nums[i];
        
        while(i<j and nums[i]>=nums[j])
        {
            int mid =i + (j-i)/2;
            if(nums[mid]>nums[j])
                i = mid+1;
            else if(nums[mid]<nums[i])
                j = mid,i++;
            else
                j--;
        }
        
        return nums[i];
    }
};