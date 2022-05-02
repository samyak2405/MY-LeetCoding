class Solution {
public:
    
    // int f(int i,string s,unordered_set<string> &s1,vector<int> &dp)
    // {
    //     if(i==s.length())
    //         return 1;
    //     if(dp[i]!=-1)
    //         return dp[i];
    //     for(int k = i;k<s.length();k++)
    //     {
    //         if(s1.find(s.substr(i,k-i+1))!=s1.end() and f(k+1,s,s1,dp))
    //             return dp[i] = 1;
    //     }
    //     return dp[i] = 0;
    // }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> s1;
        for(auto it:wordDict)
            s1.insert(it);
        int n = s.length();
        // vector<int> dp(n,-1);
        // return f(0,s,s1,dp);
        vector<int> dp(n+1,0);
        dp[n] = 1;
        for(int i = n;i>=0;i--)
        {
            for(int k = i;k<s.length();k++)
            {
                if(s1.find(s.substr(i,k-i+1))!=s1.end() and dp[k+1])
                    dp[i] = 1;
            }
        }
        return dp[0];
    }
};