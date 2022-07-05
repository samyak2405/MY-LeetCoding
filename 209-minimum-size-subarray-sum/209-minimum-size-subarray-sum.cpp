class Solution {
public:
    
    
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 1e9;
        int n = nums.size();
        vector<int> sums(n+1,0);
        for(int i =1;i<=n;i++)
            sums[i] = sums[i-1] + nums[i-1];
        
        for(int i = 1;i<=n;i++)
        {
            int to_find = target+sums[i-1];
            auto bound = lower_bound(sums.begin(),sums.end(),to_find);
            if(bound!=sums.end())
                len = min(len,static_cast<int>(bound-(sums.begin()+i-1)));
        }
        if(len==1e9)
            return 0;
        return len;
    }
};