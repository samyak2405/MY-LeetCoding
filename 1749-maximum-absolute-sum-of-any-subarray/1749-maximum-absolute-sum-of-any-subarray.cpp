class Solution {
public:
    
    int smallestSum(vector<int> &nums)
    {
        int curr_sum = 0;
        int overall_sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(curr_sum<=0)
                curr_sum+=nums[i];
            else
                curr_sum = nums[i];
            if(curr_sum<overall_sum)
                overall_sum = curr_sum;
        }
        return overall_sum;
    }
    
    int largestSum(vector<int> &nums)
    {
        int curr_sum = 0;
        int overall_sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(curr_sum>=0)
                curr_sum+=nums[i];
            else
                curr_sum = nums[i];
            if(curr_sum>overall_sum)
                overall_sum = curr_sum;
        }
        return overall_sum;
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
        return max(largestSum(nums),abs(smallestSum(nums)));
    }
};