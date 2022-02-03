class Solution {
public:
    
    void solve(vector<int> &nums,int index,set<vector<int>> &s1)
    {
        if(index>=nums.size())
        {
            s1.insert(nums);
            return;
        }
        for(int i = index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            solve(nums,index+1,s1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s1;
        solve(nums,0,s1);
        for(auto it:s1)
            res.push_back(it);
        
        return res;
    }
};