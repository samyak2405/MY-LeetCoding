class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<long long> dp(n+1,0);
        dp[0] = 1;
        vector<int> last(26,-1);
        int mod = 1e9+7;
        for(int i = 1;i<n+1;i++)
        {
            int x = s[i-1]-'a';
            dp[i] = dp[i-1]*2%mod;
            if(last[x]>=0)
                dp[i] -= dp[last[x]];
            dp[i]%=mod;
            last[x] = i-1;
        }
        dp[n]--;
        if(dp[n]<0)
            dp[n]+=mod;
        return dp[n];
    }
};