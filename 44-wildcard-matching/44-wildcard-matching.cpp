class Solution {
public:
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int i = 1;i<n+1;i++)
            dp[0][i] = 0;
        for(int i = 1;i<m+1;i++)
        {
            bool flag = true;
            for(int j = 1;j<=i;j++)
                if(p[j-1]!='*')
                {
                    flag = false;
                    break;
                }
            dp[i][0] = flag;
        }
        
        for(int i = 1;i<m+1;i++)
        {
            for(int j = 1;j<n+1;j++)
            {
                if(p[i-1]==s[j-1] or p[i-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1]=='*')
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                else
                    dp[i][j] = false;
            }
            
        }
        
        return dp[m][n];
    }
};