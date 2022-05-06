class Solution {
public:
    
    int f(int i,int j,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(i==j)
            return dp[i][j] = nums[i];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int front_pick = nums[i] + min(f(i+2,j,nums,dp),f(i+1,j-1,nums,dp));
        int back_pick = nums[j] + min(f(i+1,j-1,nums,dp),f(i,j-2,nums,dp));
        return dp[i][j] = max(front_pick,back_pick);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return true;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int score = f(0,n-1,nums,dp);
        int sum = 0;
        for(int i = 0;i<n;i++)
            sum+=nums[i];
        sum-= score;
        if(score>=sum)
            return true;
        return false;
    }
};