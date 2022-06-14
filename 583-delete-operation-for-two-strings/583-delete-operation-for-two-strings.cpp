class Solution {
public:
    
    // int f(string s1,string s2,int i,int j,vector<vector<int>> &dp)
    // {
    //     if(i==s1.length() or j == s2.length())
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(s1[i]==s2[j])
    //         return dp[i][j] = 1+ f(s1,s2,i+1,j+1,dp);
    //     else
    //         return dp[i][j] = max(f(s1,s2,i,j+1,dp),f(s1,s2,i+1,j,dp));
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        for(int i =0;i<n+1;i++)
        {
            for(int j = 0;j<m+1;j++)
            {
                if(i==0 or j==0)
                    dp[i][j] = 0;
                else if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int minDistance(string word1, string word2) {
        // vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        // int len = f(word1,word2,0,0,dp);
        int len = longestCommonSubsequence(word1,word2);
        return word1.length()-len + word2.length()-len;
    }
};