class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> res1;
        for(int i = 0;i<pow(2,n);i++)
        {
            vector<int> tmp;
            for(int j = 0;j<n;j++)
                if(i&(1<<j))
                    tmp.push_back(nums[j]);
            res1.insert(tmp);
        }
        for(auto it:res1)
            res.push_back(it);
        return res;
    }
};