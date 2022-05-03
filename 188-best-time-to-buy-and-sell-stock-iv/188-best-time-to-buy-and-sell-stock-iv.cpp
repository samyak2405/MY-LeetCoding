class Solution {
public:
    
    //recursion
    // int f(int ind,bool buy,vector<int> &prices,int k)
    // {
    //     if(ind==prices.size())
    //         return 0;
    //     if(k==0)
    //         return 0;
    //     int profit = 0;
    //     if(buy)
    //         profit = max(-prices[ind]+f(ind+1,0,prices,k),f(ind+1,1,prices,k));
    //     else
    //         profit = max(prices[ind]+f(ind+1,1,prices,k-1),f(ind+1,0,prices,k));
    //     return profit;
    // }
    
    //memoization
    int f(int ind,bool buy,vector<int> &prices,int k,vector<vector<vector<int>>> &dp)
    {
        if(ind==prices.size())
            return 0;
        if(k==0)
            return 0;
        if(dp[ind][buy][k]!=-1)
            return dp[ind][buy][k];
        int profit = 0;
        if(buy)
            profit = max(-prices[ind]+f(ind+1,0,prices,k,dp),f(ind+1,1,prices,k,dp));
        else
            profit = max(prices[ind]+f(ind+1,1,prices,k-1,dp),f(ind+1,0,prices,k,dp));
        return dp[ind][buy][k] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //recursion
        // return f(0,1,prices,k);
        
        //memoization
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(k+1,-1)));
        return f(0,1,prices,k,dp);
    }
};