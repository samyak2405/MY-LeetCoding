class Solution {
public:
    
    void reversal(vector<int> &nums,int l,int r)
    {
        if(l>=r)
            return;
        swap(nums[l],nums[r]);
        reversal(nums,l+1,r-1);
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reversal(nums,0,n-1);
        reversal(nums,0,k-1);
        reversal(nums,k,n-1);
        return;
    }
};