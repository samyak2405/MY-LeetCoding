class Solution {
public:
    int countElements(vector<int>& nums) {
        int minim = INT_MAX,maxim = INT_MIN;
        for(int i = 0;i<nums.size();i++)
        {
            minim = min(minim,nums[i]);
            maxim = max(maxim,nums[i]);
        }
        int cnt =0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]!=minim and nums[i]!=maxim)
            {
                cnt++;
            }
        }
        return cnt;
    }
};