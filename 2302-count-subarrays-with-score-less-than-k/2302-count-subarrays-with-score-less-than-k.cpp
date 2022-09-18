class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0,j = 0;
        long long cnt = 0;
        long long sum = 0;
        int n = nums.size();
        while(j<n)
        {
            sum += nums[j];
            while(sum*(j-i+1)>=k)
            {
                sum-=nums[i];
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
};