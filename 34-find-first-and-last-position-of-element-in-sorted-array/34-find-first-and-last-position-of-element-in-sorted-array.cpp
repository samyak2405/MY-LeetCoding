class Solution {
public:
    
    int lbs(vector<int> &nums,int target)
    {
        int ans = -1;
        int low = 0,high = nums.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return ans;
    }
    
    int fbs(vector<int> &nums,int target)
    {
        int ans = -1;
        int low = 0,high = nums.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{fbs(nums,target),lbs(nums,target)};
    }
};