class Solution {
public:
    
    bool f(int i,int j,string s,string p,vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool ans;
        if(j==p.length())
            ans = i==s.length();
        else
        {
            bool first_match = (i<s.length() and (p[j]==s[i] or p[j]=='.'));
            if(j+1<p.length() and p[j+1]=='*')
                ans = f(i,j+2,s,p,dp) or first_match and f(i+1,j,s,p,dp);
            else
                ans = first_match and f(i+1,j+1,s,p,dp);
        }
        return dp[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
        int n = s.length(),m = p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,s,p,dp);
    }
};