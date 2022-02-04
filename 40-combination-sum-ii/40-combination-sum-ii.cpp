class Solution {
public:
    
    void solve(vector<int>& nums, int target,int index,vector<vector<int>> &res,vector<int> &tmp)
    {
        if(target==0)
        {
            res.push_back(tmp);
            return;
        }
        
        for(int i = index;i<nums.size();i++)
        {
            if(i> index and nums[i-1]==nums[i])
                continue;
            if(target<nums[i])
                break;
            tmp.push_back(nums[i]);
            solve(nums,target-nums[i],i+1,res,tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        solve(nums,target,0,res,tmp);
        
        return res;
    }
};