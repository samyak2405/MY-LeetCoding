class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        prev[0]=curr[0] = 1;
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                    curr[j] = curr[j-coins[i-1]]+prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return prev[amount];
    }
};