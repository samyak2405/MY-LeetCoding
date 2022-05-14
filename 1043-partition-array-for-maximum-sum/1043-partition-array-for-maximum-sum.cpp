class Solution {
public:
    int f(int ind,int k,vector<int> &arr,int n,vector<int> &dp)
    {
        if(ind==arr.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int len = 0;
        int maxans = INT_MIN;
        int max_element = arr[ind];
        int limit = min(ind+k,n);
        for(int j = ind;j<limit;j++)
        {
            len++;
            max_element = max(max_element,arr[j]);
            int cost = len*max_element + f(j+1,k,arr,n,dp);
            maxans = max(maxans,cost);
        }
        
        return dp[ind] = maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return f(0,k,arr,n,dp);
    }
};