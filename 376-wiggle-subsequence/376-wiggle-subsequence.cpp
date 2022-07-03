class Solution {
public:
    
    int f(int ind,int prev,int flag,vector<int> &nums,vector<vector<vector<int>>> &dp)
    {
        if(ind==nums.size())
            return 0;
        if(dp[ind][prev+1][flag]!=-1)
            return dp[ind][prev+1][flag];
        int nt = f(ind+1,prev,flag,nums,dp);
        int t = 0;
        if(prev==-1)
            t = 1 + f(ind+1,ind,1-flag,nums,dp);
        else
        {
            if(!flag and (nums[ind]>nums[prev]))
                t = 1 + f(ind+1,ind,1-flag,nums,dp);
            else if(flag and nums[ind]<nums[prev])
                t = 1+f(ind+1,ind,1-flag,nums,dp);
        }
        return dp[ind][prev+1][flag] = max(t,nt);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return max(f(0,-1,0,nums,dp),f(0,-1,1,nums,dp));
    }
};