class Solution {
public:
    
    int f(int k,int n,vector<vector<int>> &dp)
    {
        if(n==0 or n==1)
            return n;
        if(k==1)
            return n;
        if(dp[k][n]!=-1)
            return dp[k][n];
        int mn = INT_MAX;
        int low = 1;
        int high = n;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int broken = f(k-1,mid-1,dp);
            int not_broken = f(k,n-mid,dp);
            int tmp = 1+max(broken,not_broken);
            if(broken<not_broken)
                low = mid+1;
            else
                high = mid-1;
            mn = min(mn,tmp);
        }
        return dp[k][n] =mn;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return f(k,n,dp);
    }
};