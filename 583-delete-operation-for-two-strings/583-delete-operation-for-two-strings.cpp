class Solution {
public:
    
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
        int len = longestCommonSubsequence(word1,word2);
        return word1.length()-len + word2.length()-len;
    }
};