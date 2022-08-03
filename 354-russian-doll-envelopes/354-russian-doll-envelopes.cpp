class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return b[1]<a[1];
        else
            return a[0]<b[0];
    }
    
    #define vvi vector<vector<int>>
    // int f(int ind,int prev,vvi &env,vvi &dp)
    // {
    //     if(ind==env.size())
    //         return 0;
    //     if(dp[ind][prev+1]!=-1)
    //         return dp[ind][prev+1];
    //     int len = f(ind+1,prev,env,dp);
    //     if(prev==-1 or (env[prev][0]<env[ind][0] and env[prev][1]<env[ind][1]))
    //         len = max(len,1+f(ind+1,ind,env,dp));
    //     return dp[ind][prev+1] = len;
    // }
    
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),cmp);
        int n = env.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return f(0,-1,env,dp);
        // vector<int> dp(n+1,1);
        // int maxi = INT_MIN;
        // for(int i = 0;i<n;i++)
        // {
        //     for(int prev = 0;prev<i;prev++)
        //     {
        //         if((env[prev][0]<env[i][0] and env[prev][1]<env[i][1]) and 1+dp[prev]>dp[i])
        //             dp[i] = dp[prev]+1;
        //     }
        //     maxi = max(maxi,dp[i]);
        // }
        // return maxi;
        vector<int> dp;
        for(auto en:env)
        {
            auto it = lower_bound(dp.begin(),dp.end(),en[1]) - dp.begin();
            if(it==dp.size())
                dp.push_back(en[1]);
            else
                dp[it] = en[1];
        }
        return dp.size();
    }
};