class Solution {
public:
    int minInsertions(string s) {
        string srev = s;
        reverse(srev.begin(),srev.end());
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<n+1;j++)
            {
                if(i==0 or j==0)
                    continue;
                else if(s[i-1]==srev[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return s.length()-dp[n][n];
    }
};