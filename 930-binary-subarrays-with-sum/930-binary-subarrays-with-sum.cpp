class Solution {
public:
    
    int numSubarraysWithSum(vector<int>& nums, int S) {
        int p = 0,i = 0,res = 0,c = 0;
        int j = 0;
        int n = nums.size();
        while(j<n)
        {
            c+=nums[j];
            while(c>S and i<j)
            {
                p = 0;
                c-=nums[i];
                i++;
            }
            while(nums[i]==0 and i<j)
            {
                p++;
                c-=nums[i];
                i++;
            }
            if(c==S)
                res+=p+1;
            j++;
        }
        return res;
    }
};