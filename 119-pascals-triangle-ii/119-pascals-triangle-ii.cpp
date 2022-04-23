class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> dp(numRows+1);
        for(int i = 0;i<numRows+1;i++)
        {
            dp[i].resize(i+1);
            dp[i][0] = dp[i][i] = 1;
            for(int j = 1;j<i;j++)
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
        return dp[numRows];
    }
};