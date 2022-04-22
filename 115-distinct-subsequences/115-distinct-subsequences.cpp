class Solution {
public:
    
    int solve(string s,string t,int i,int j,vector<vector<int>> &dp)
    {
        if(j==0)
            return 1;
        if(i==0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i-1]==t[j-1])
            return dp[i][j] = solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
        else
            return dp[i][j] = solve(s,t,i-1,j,dp);
    }
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,n,m,dp);
//         vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        
//         for(int i = 0;i<n+1;i++)
//             dp[i][0] = 1;
        
//         for(int i = 1;i<n+1;i++)
//         {
//             for(int j = 1;j<m+1;j++)
//             {
//                 if(s[i-1]==t[j-1])
//                     dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
//                 else
//                     dp[i][j] = dp[i-1][j];
//             }
//         }
        
//         return (int)dp[n][m];
        vector<double> prev(m+1,0),curr(m+1,0);
        prev[0] = curr[0] = 1;
        
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<m+1;j++)
            {
                if(s[i-1]==t[j-1])
                    curr[j] = prev[j-1]+prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return (int)prev[m];
        
    }
};