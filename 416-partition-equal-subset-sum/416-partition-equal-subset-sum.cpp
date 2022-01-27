class Solution {
public:
    
    bool isSubset(vector<int> &arr,int N,int sum)
    {
        int dp[N+1][sum+1];
        
        for(int i =0;i<N+1;i++)
            dp[i][0] = true;
        
        for(int i = 0;i<sum+1;i++)
            dp[0][i] = false;
        
        for(int i = 1;i<N+1;i++)
            for(int j = 1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            
        return dp[N][sum];
    }
    
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        int N = arr.size();
        for(int i = 0;i<N;i++)
            sum+=arr[i];
            
        if(sum%2!=0)
            return false;
        return isSubset(arr,N,sum/2);
    }
};