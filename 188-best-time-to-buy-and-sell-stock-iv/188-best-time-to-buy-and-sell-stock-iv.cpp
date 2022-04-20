class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(k+1,0)));
        
        for(int i = n-1;i>=0;i--)
        {
            for(int j = 0;j<2;j++)
            {
                int profit = 0;
                for(int l = 1;l<k+1;l++)
                {
                    if(j)
                        profit = max(-prices[i]+dp[i+1][0][l],dp[i+1][1][l]);
                    else
                        profit = max(prices[i]+dp[i+1][1][l-1],dp[i+1][0][l]);
                    dp[i][j][l] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};