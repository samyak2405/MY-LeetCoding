class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int n = nums.size();
        int i = 0,j = 0;
        int res = -1;
        while(j<n)
        {
            if(nums[j]==0)
                zeros++;
            while(zeros>k)
            {
                if(nums[i]==0)
                    zeros--;
                i++;
            }
            res = max(res,j-i+1);
            j++;
            
        }
        return res;
    }
};