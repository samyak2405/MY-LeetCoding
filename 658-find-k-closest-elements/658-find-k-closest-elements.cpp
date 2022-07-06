class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int low = 0,high = n-k;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            if(x-nums[mid]>nums[mid+k]-x)
                low = mid+1;
            else
                high = mid;
        }
        vector<int> res;
        while(k--)
            res.emplace_back(nums[low++]);
        return res;
    }
};