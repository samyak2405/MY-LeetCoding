class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int n = nums.size();
        int prev1 = 0;
        int prev2 = 0;
        int prev11 = 0;
        int prev12 = 0;
        
        for(int i = 0;i<n-1;i++)
        {
            int tmp = prev1;
            prev1 = max(prev2+nums[i],prev1);
            prev2 = tmp;
        }
        
        for(int i = 1;i<n;i++)
        {
            int tmp = prev11;
            prev11 = max(prev12+nums[i],prev11);
            prev12 = tmp;
        }
        
        return max(prev1,prev11);
    }
};