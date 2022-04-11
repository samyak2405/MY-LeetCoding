class Solution {
public:
    
    int bs(vector<int> &nums,int l,int r,int target)
    {
        while(l<=r)
        {
            int mid = l + (r - l)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                r = mid-1;
            else
                l = mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        
        while(low<high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[high])
                low = mid+1;
            else
                high = mid;
        }
        cout<<low;
        
        int val = bs(nums,0,low-1,target);
        if(val!=-1)
            return val;
        return bs(nums,low,nums.size()-1,target);
    }
};