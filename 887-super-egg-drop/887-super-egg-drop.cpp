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
        int low = 1;
        int high = f;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int breaked = solve(mid-1,e-1,dp);
            int not_breaked = solve(f-mid,e,dp);
            int tmp = max(breaked,not_breaked)+1;
            if(breaked<not_breaked)
                low = mid+1;
            else
                high = mid-1;
            mn = min(mn,tmp);
        }
        return dp[f][e] = mn;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};