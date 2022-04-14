class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int res = nums[0];
        for(int i = 0;i<n;i++)
        {
            l = (l?l:1)*nums[i];
            r = (r?r:1)*nums[n-1-i];
            res = max(res,max(l,r));
        }
        return res;
    }
};