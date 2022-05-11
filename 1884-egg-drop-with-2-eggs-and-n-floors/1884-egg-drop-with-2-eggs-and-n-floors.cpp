class Solution {
public:
    
    int solve(int f,int e,vector<vector<int>> &dp)
    {
        if(e==0)
            return 0;
        if(e==1)
            return f;
        if(f==1 or f==0)
            return f;
        if(dp[f][e]!=-1)
            return dp[f][e];
        int mn = INT_MAX;
        for(int k = 1;k<f;k++)
        {
            int tmp = max(solve(k-1,e-1,dp),solve(f-k,e,dp));
            mn = min(mn,tmp);
        }
        return dp[f][e] = mn+1;
    }
    
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solve(n,2,dp);
    }
};