class Solution {
public:
    
    int profit(vector<int> &prices,int fee,int ind,bool buy,vector<vector<int>> &dp)
    {
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        int profits = 0;
        if(buy)
            profits = max(-prices[ind]+profit(prices,fee,ind+1,0,dp),profit(prices,fee,ind+1,1,dp));
        else
            profits = max(prices[ind]-fee+profit(prices,fee,ind+1,1,dp),profit(prices,fee,ind+1,0,dp));
        return dp[ind][buy]=profits;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return profit(prices,fee,0,1,dp);
    }
};