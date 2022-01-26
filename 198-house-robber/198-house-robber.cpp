class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=0)
            return 0;
        int prev1 = 0;
        int prev2 = 0;
        
        for(auto it:nums)
        {
            int tmp = prev1;
            prev1 = max(it+prev2,prev1);
            prev2 =tmp;
        }
        
        return prev1;
    }
};