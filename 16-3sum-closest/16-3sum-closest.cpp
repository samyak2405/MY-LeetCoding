class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3)
            return 0;
        sort(nums.begin(),nums.end());
        int x = nums[0] + nums[1] + nums[2];
        for(int i = 0;i<n;i++)
        {
            if(i==0 or (i>0 and nums[i]!=nums[i-1]))
            {
                int j = i+1;
                int k = n-1;
                while(j<k)
                {
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum==target)
                        return sum;
                    if(abs(target-sum)<abs(target-x))
                        x = sum;
                    else if(sum>target)
                        k--;
                    else
                        j++;
                }
            }
        }
        return x;
    }
};