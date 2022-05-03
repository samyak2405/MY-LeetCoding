class Solution {
public:
    
    // int f(int ind,bool buy,vector<int> &prices,vector<vector<int>> &dp)
    // {
    //     if(ind==prices.size())
    //         return 0;
    //     if(dp[ind][buy]!=-1)
    //         return dp[ind][buy];
    //     int profit = 0;
    //     if(buy)
    //         profit = max(-prices[ind]+f(ind+1,0,prices,dp),f(ind+1,1,prices,dp));
    //     else
    //         profit = max(prices[ind]+f(ind+1,1,prices,dp),f(ind+1,0,prices,dp));
    //     return dp[ind][buy] = profit;
    // }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //recursion
        // return f(0,1,prices);
        
        //memoization
        //vector<vector<int>> dp(n,vector<int>(2,-1));
        // return f(0,1,prices,dp);
        
        //tabulation
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        
        for(int i = n-1;i>=0;i--)
        {
            int profit = 0;
            for(int buy = 0;buy<2;buy++)
            {
                if(buy)
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else
                    profit = max(prices[i]+dp[i+1][1],dp[i+1][0]);
                dp[i][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
};