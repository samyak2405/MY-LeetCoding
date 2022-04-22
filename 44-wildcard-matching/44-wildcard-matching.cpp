class Solution {
public:
    
    // bool f(string p,string s,int i,int j,vector<vector<int>> &dp)
    // {
    //     if(i==0 and j==0)
    //         return true;
    //     if(i==0 and j>0)
    //         return false;
    //     if(j==0 and i>0)
    //     {
    //         for(int k = 1;k<=i;k++)
    //             if(p[k-1]!='*')
    //                 return false;
    //         return true;
    //     }
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(p[i-1]==s[j-1] or p[i-1]=='?')
    //         return dp[i][j] = f(p,s,i-1,j-1,dp);
    //     if(p[i-1]=='*')
    //         return dp[i][j] = f(p,s,i-1,j,dp) or f(p,s,i,j-1,dp);
    //     return false;
    // }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return f(p,s,m,n,dp);
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