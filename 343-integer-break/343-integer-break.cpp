class Solution {
public:
    
    int f(int wt,int n,vector<vector<int>> &dp)
    {
        if(wt<1 or n==0)
            return 1;
        if(wt<=n)
            return max(wt*f(wt,n-wt,dp),f(wt-1,n,dp));
        else
            return f(wt-1,n,dp);
    }
    
    int integerBreak(int n) {
        vector<vector<int>> dp(n,vector<int>(n,-1));
        if(n%2)
            return f((n/2)+1,n,dp);
        return f(n/2,n,dp);
    }
};