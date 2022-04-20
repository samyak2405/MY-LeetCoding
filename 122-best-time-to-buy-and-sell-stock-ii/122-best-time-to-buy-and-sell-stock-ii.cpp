class Solution {
public:
    
    int profit(vector<int> &prices,int index,bool buy,vector<vector<int>> &dp)
    {
        if(index==prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        int profits;
        if(buy)
            profits = max(-prices[index]+profit(prices,index+1,0,dp),profit(prices,index+1,1,dp));
        else
            profits = max(prices[index]+profit(prices,index+1,1,dp),profit(prices,index+1,0,dp));
        return dp[index][buy] = profits;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1)); 
        return profit(prices,0,1,dp);
    }
};