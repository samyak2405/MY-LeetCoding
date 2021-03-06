class Solution {
public:
    
    // int f(int wt,int n,vector<vector<int>> &dp)
    // {
    //     if(wt<1 or n==0)
    //         return 1;
    //     if(dp[wt][n]!=-1)
    //         return dp[wt][n];
    //     if(wt<=n)
    //         return dp[wt][n] = max(wt*f(wt,n-wt,dp),f(wt-1,n,dp));
    //     else
    //         return dp[wt][n] = f(wt-1,n,dp);
    // }
    
    int integerBreak(int n) {
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // if(n%2)
        //     return f((n/2)+1,n,dp);
        // return f(n/2,n,dp);
        int wt = 0;
        if(n%2)
            wt = (n/2)+1;
        else
            wt = n/2;
        vector<int> curr(n+1,0),prev(n+1,0);
        for(int i = 1;i<=wt;i++)
        {
            for(int j = 0;j<=n;j++)
            {
                if(j==0)
                    curr[j] = 1;
                else if(i<=j)
                    curr[j] = max(i*curr[j-i],prev[j]);
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return prev[n];
    }
};