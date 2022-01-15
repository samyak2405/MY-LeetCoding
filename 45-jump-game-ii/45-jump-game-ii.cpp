class Solution {
public:
    int jump(vector<int>& nums) {
        int curreach = 0;
        int curMax = 0;
        int cnt = 0;
        
        for(int i = 0;i<nums.size()-1;i++)
        {
            curMax = max(curMax,i+nums[i]);
            if(i==curreach)
            {
                cnt++;
                curreach =curMax;
            }
        }
        
        return cnt;
    }
};