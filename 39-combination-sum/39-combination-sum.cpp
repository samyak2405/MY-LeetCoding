class Solution {
public:
    
    void solve(vector<int> &nums, int target,int index,vector<vector<int>> &res,vector<int> tmp)
    {
        if(target<0)
            return;
        
        if(index==nums.size())
        {
            if(target==0)
            {
                res.push_back(tmp);
            }
            return;
        }
        target-=nums[index];
        tmp.push_back(nums[index]);
        if(target>=nums[index])
            solve(nums,target,index,res,tmp);
        else
            solve(nums,target,index+1,res,tmp);
        target+=nums[index];
        tmp.pop_back();
        solve(nums,target,index+1,res,tmp);
        return ;
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        solve(nums,target,0,res,vector<int>());
        return res;
    }
};