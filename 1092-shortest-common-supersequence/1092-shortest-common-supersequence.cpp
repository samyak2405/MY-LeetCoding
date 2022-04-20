class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.length(),m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<m+1;j++)
            {
                if(i==0 or j==0)
                    dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string res;
        int i = n,j = m;
        
        while(i>0 and j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                res+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                res+=s1[i-1];
                i--;
            }
            else
            {
                res+=s2[j-1];
                j--;
            }
        }
        while(i>0)
        {
            res+=s1[i-1];
            i--;
        }
        while(j>0)
        {
            res+=s2[j-1];
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};