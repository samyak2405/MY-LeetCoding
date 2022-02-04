class Solution {
public:
    
    void combine(vector<int> &nums,int target,vector<vector<int>> &res,int index,vector<int> &tmp)
    {
        if(!target)
        {
            res.push_back(tmp);
            return;
        }
        for(int i = index;i!=nums.size() and target>=nums[i];i++)
        {
            tmp.push_back(nums[i]);
            combine(nums,target-nums[i],res,i,tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        combine(nums,target,res,0,tmp);
        return res;
        
    }
};