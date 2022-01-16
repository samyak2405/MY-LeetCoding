class Solution {
public:
    long long mostPoints(vector<vector<int>>& que) {
        int n = que.size();
        if(n==0)
            return 0;
        vector<long long> dp(n,0);
        dp[n-1] = que[n-1][0];
        for(int i = n-2;i>=0;i--)
        {
            dp[i] = dp[i+1];
            
            long long curr = que[i][0];
            
            int forward_index = i+ que[i][1] +1;
            if(forward_index<n)
                curr += dp[forward_index];
            dp[i] = max(dp[i],curr);
        }
        
        return dp[0];
    }
};