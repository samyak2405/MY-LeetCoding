class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i-1>=0)
        {
            if(nums[i]>nums[i-1])
                break;
            i--;
        }
        if(i==0)
        {
            reverse(nums.begin()+i,nums.end());
            return ;
        }
        int a = nums[i-1];
        int j = i;
        for(;j<n;j++)
        {
            if(nums[j]<=a)
                break;
        }
        swap(nums[i-1],nums[j-1]);
        j = n-1;
        while(i<j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};