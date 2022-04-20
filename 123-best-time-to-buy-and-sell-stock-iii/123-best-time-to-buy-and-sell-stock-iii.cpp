class Solution {
public:
    
    int profit(vector<int> &prices,int ind,bool buy,int cap,vector<vector<vector<int>>> &dp)
    {
        if(cap==0)
            return 0;
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        int profits = 0;
        if(buy)
            profits = max(-prices[ind]+profit(prices,ind+1,0,cap,dp),profit(prices,ind+1,1,cap,dp));
        else
            profits = max(prices[ind]+profit(prices,ind+1,1,cap-1,dp),profit(prices,ind+1,0,cap,dp));
        return dp[ind][buy][cap] = profits;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return profit(prices,0,1,2,dp);
    }
};