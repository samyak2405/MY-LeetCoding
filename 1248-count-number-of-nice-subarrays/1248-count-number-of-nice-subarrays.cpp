class Solution {
public:
    
    int atmost(vector<int> &nums,int k)
    {
        int j = 0;
        int res = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            k-=nums[i]%2;
            while(k<0)
            {
                k+=nums[j]%2;
                j++;
            }
            res+=i-j+1;
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};