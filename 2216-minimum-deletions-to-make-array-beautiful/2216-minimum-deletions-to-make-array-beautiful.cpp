class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int d = 0;
        int n = nums.size();
        for(int i = 0;i<n-1;i++)
        {
            int new_ind = i-d;
            if(new_ind%2==0 and nums[i]==nums[i+1])
            {
                d++;
            }
        }
        return ((n-d)%2)?d+1:d;
    }
};