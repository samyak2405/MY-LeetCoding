class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5,vector<int>(n+1,1));
        for(int i = 2;i<=n;i++)
        {
            for(int j = 3;j>=0;j--)
            {
                dp[j][i] = dp[j+1][i] + dp[j][i-1];
            }
        }
        int sum = 0;
        
        for(int i=0;i<5;i++)
            sum+=dp[i][n];
        
        return sum;
    }
};