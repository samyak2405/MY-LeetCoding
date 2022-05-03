class Solution {
public:
    
    // int f(int ind,bool buy,vector<int> &prices,int cap)
    // {
    //     if(ind==prices.size())
    //         return 0;
    //     if(!cap)
    //         return 0;
    //     int profit = 0;
    //     if(buy)
    //         profit = max(-prices[ind]+f(ind+1,0,prices,cap),f(ind+1,1,prices,cap));
    //     else
    //         profit = max(prices[ind]+f(ind+1,1,prices,cap-1),f(ind+1,0,prices,cap));
    //     return profit;
    // }
    int f(int ind,bool buy,vector<int> &prices,int cap,vector<vector<vector<int>>> &dp)
    {
        if(ind==prices.size())
            return 0;
        if(!cap)
            return 0;
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        int profit = 0;
        if(buy)
            profit = max(-prices[ind]+f(ind+1,0,prices,cap,dp),f(ind+1,1,prices,cap,dp));
        else
            profit = max(prices[ind]+f(ind+1,1,prices,cap-1,dp),f(ind+1,0,prices,cap,dp));
        return dp[ind][buy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //recursion
        // return f(0,1,prices,2);
        
        //memoization
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
        return f(0,1,prices,2,dp);
    }
};