class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<n-2;i++)
        {
            if(i==0 or (i>0 and nums[i-1]!=nums[i]))
            {
                int j = i+1,k = n-1;
                int sum = -nums[i];
                while(j<k)
                {
                    int ans = nums[j]+nums[k];
                    if(sum==ans)
                    {
                        vector<int> tmp = {nums[i],nums[j],nums[k]};
                        res.emplace_back(tmp);
                        while(j<k and nums[j]==nums[j+1])
                            j++;
                        while(j<k and nums[k]==nums[k-1])
                            k--;
                        j++;
                        k--;
                    }
                    else if(sum>ans)
                        j++;
                    else
                        k--;
                }
            }
            
        }
        return res;
    }
};