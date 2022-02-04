class Solution {
public:
    
    void combine(vector<int> &nums,int target,vector<vector<int>> &res,int index,vector<int> tmp)
    {
        if(target<0)
            return;
        if(index==nums.size())
        {
            if(!target)
                res.push_back(tmp);
            return;
        }
        if(nums[index]<=target)
        {
            tmp.push_back(nums[index]);
            combine(nums,target-nums[index],res,index,tmp);
            tmp.pop_back();
        }
        combine(nums,target,res,index+1,tmp);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        combine(nums,target,res,0,tmp);
        return res;
        
    }
};