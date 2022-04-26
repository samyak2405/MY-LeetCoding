class Solution {
public:
    
//     int f(int ind,int prev,vector<int> &nums,vector<vector<int>> &dp)
//     {
//         if(ind==nums.size())
//             return 0;
//         if(dp[ind][prev+1]!=-1)
//             return dp[ind][prev+1];
//         int len = f(ind+1,prev,nums,dp);
//         if(prev==-1 or nums[prev]<nums[ind])
//             len = max(len,1+f(ind+1,ind,nums,dp));
//         return dp[ind][prev+1] = len;
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return f(0,-1,nums,dp);
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> curr(n+1,0),ahead(n+1,0);
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int prev = ind-1;prev>=-1;prev--)
            {
                int len = ahead[prev+1];
                if(prev == -1 or nums[prev]<nums[ind])
                    len = max(len,1+ahead[ind+1]);
                curr[prev+1] = len;
            }
            ahead = curr;
        }
        return ahead[0];
    }
};