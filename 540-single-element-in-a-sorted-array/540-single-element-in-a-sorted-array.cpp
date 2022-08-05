class Solution {
public:
    
    bool isTrue(vector<int> &nums,int ind)
    {
        if(ind%2)
            return nums[ind]!=nums[ind-1];
        else
            return nums[ind]!=nums[ind+1];
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = -1,high = n-1;
        while(low+1<high)
        {
            int mid = low+(high-low)/2;
            if(isTrue(nums,mid))
                high = mid;
            else
                low = mid;
        }
        return nums[high];
    }
};