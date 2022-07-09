class Solution {
public:
//     int f(int ind,int k,vector<int> &nums,vector<int> &dp)
//     {
//         if(ind==nums.size()-1)
//             return nums[nums.size()-1];
//         if(dp[ind]!=-1)
//             return dp[ind];
//         int ans = INT_MIN;
//         for(int i = ind+1;i<=min((int)nums.size()-1,ind+k);i++)
//         {
//             int tmp = nums[ind] + f(i,k,nums,dp);
//             ans = max(ans,tmp);
//         }
//         return dp[ind] = ans;
//     }
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<int> dp(n,-1);
        // int val = f(0,k,nums,dp);
        // return val;
        // vector<int> dp(n,INT_MIN);
        // dp[0] = nums[0];
        // for(int i = 1;i<n;i++)
        // {
        //     for(int j = 1;j<=min(i,k);j++)
        //     {
        //         dp[i] = max(dp[i],nums[i]+dp[i-j]);
        //     }
        // }
        // return dp[n-1];
        vector<int> dp(n);
        dp[0] = nums[0];
        deque<int> q{0};
        for(int i = 1;i<n;i++)
        {
            if(i-k>q.front())
                q.pop_front();
            dp[i] = nums[i] + dp[q.front()];
            while(!q.empty() and dp[q.back()]<=dp[i])
                q.pop_back();
            q.push_back(i);
        }
        return dp.back();
    }
};