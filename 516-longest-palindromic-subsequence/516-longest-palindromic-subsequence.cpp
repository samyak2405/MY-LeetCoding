class Solution {
public:
    
    // int f(string s1,string s2,int i,int j,vector<vector<int>> &dp)
    // {
    //     if(i==0 or j==0)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(s1[i-1]==s2[j-1])
    //         return dp[i][j] = 1+f(s1,s2,i-1,j-1,dp);
    //     else
    //         return dp[i][j] = max(f(s1,s2,i-1,j,dp),f(s1,s2,i,j-1,dp));
    // }
    
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        int n = s1.length(),m = s2.length();
        reverse(s2.begin(),s2.end());
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return f(s1,s2,n,m,dp);
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<m+1;j++)
            {
                if(i==0 or j==0)
                    continue;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};