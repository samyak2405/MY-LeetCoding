class Solution {
public:
    
    int ceiling(vector<int> &nums,int i,int target)
    {
        int ans = -1;
        int low = 0,high = nums.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]<target)
                high = mid-1;
            else
            {
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_dist = 0;
        for(int i = 0;i<nums1.size();i++)
        {
            int val = ceiling(nums2,i,nums1[i]);
            if(val!=-1)
                max_dist = max(max_dist,val-i);
        }
        return max_dist;
    }
};