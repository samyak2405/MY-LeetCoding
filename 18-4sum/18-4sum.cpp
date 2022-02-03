class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<=3)
            return res;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i = 0;i<n;i++)
        {
            int sum = target - nums[i];
            for(int j = i+1;j<n;j++)
            {
                int sum1 = sum - nums[j];
                int k = j+1;
                int l = n-1;
                while(k<l)
                {
                    int a = nums[k];
                    int b = nums[l];
                    int s = a+b;
                    if(s==sum1)
                    {
                        res.push_back(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        do{k++;}while(k<l and nums[k]==a);
                        do{l--;}while(k<l and nums[l]==b);
                    }
                    else if(s>sum1)
                        l--;
                    else
                        k++;
                }
                while(j+1<n and nums[j]==nums[j+1]) j++;
            }
            while(i+1<n and nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};