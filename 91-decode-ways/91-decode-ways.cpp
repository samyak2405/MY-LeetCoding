class Solution {
public:
    
    int f(string s,int i,vector<int> &dp)
    {
        if(i==s.length())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int ans = 0;
        if(s[i]!='0')
            ans+=f(s,i+1,dp);
        if(i+1<s.length() and (s[i]=='1' or s[i]=='2' and s[i+1]<='6'))
            ans+=f(s,i+2,dp);
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return f(s,0,dp);
    }
};