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
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i = n-1;i>=0;i--)
        {
            int profit = 0;
            for(int j = 0;j<2;j++)
            {
                for(int k = 1;k<3;k++)
                {
                    if(j)
                        profit = max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    else
                        profit = max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    dp[i][j][k] = profit;
                }
            }
        }
        
        return dp[0][1][2];
    }
};