class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> mp;
        for(int i = 0;i<nums.size();i++)
            for(int j = 0;j<nums[i].size();j++)
                    mp[i+j].push_back(nums[i][j]);
        vector<int> res;
        for(auto it:mp)
        {
            vector<int> tmp = it.second;
            reverse(tmp.begin(),tmp.end());
            for(auto itr:tmp)
                res.push_back(itr);
        }
        return res;
    }
};