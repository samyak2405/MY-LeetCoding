class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        for(int i = 0;i<pow(2,n);i++)
        {
            vector<int> tmp;
            for(int j = 0;j<n;j++)
            {
                if(1&(i>>j))
                    tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        
        
        return res;
    }
};