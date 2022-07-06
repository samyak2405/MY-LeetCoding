class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        set<vector<int>> s1;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<n-2;i++)
        {
            int j = i+1,k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    vector<int> tmp = {nums[i],nums[j],nums[k]};
                    s1.insert(tmp);
                    j++;
                    k--;
                }
                else if(sum<0)
                    j++;
                else
                    k--;
            }
        }
        for(auto it:s1)
            res.push_back(it);
        return res;
    }
};