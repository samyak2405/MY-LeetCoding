class Solution {
public:
    
    // int f(string s1,string s2,int i,int j,vector<vector<int>> &dp)
    // {
    //     if(j<0)
    //         return i+1;
    //     if(i<0)
    //         return j+1;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(s1[i]==s2[j])
    //         return dp[i][j] = f(s1,s2,i-1,j-1,dp);
    //     else
    //     {
    //         return dp[i][j] = min(1+f(s1,s2,i,j-1,dp),min(1+f(s1,s2,i-1,j,dp),1+f(s1,s2,i-1,j-1,dp)));
    //     }
    // }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(word1,word2,n-1,m-1,dp);
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0;i<n+1;i++)
            dp[i][0] = i;
        for(int i = 0;i<m+1;i++)
            dp[0][i] = i;
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<m+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(1+dp[i][j-1],min(1+dp[i-1][j],1+dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};