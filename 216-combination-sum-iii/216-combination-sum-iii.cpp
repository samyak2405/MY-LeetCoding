class Solution {
public:
    
    void solve(vector<int> &nums,int k,int n,int index,vector<vector<int>> &res,vector<int> &tmp)
    {
        if(n<0)
            return;
        if(n==0)
        {
            if(tmp.size()==k)
                res.push_back(tmp);
            return;
        }
        for(int i = index;i!=nums.size();i++)
        {
            tmp.push_back(nums[i]);
            solve(nums,k,n-nums[i],i+1,res,tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1;i<=9;i++)
            nums.push_back(i);
        vector<vector<int>> res;
        vector<int> tmp;
        solve(nums,k,n,0,res,tmp);
        
        return res;
    }
};