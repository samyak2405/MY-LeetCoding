// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool solve(vector<int> &arr,int sum,int n)
    {
        if(sum==0 or n==0)
            return true;
        if(arr[n-1]<=sum)
            return solve(arr,sum-arr[n-1],n-1) or solve(arr,sum,n-1);
        if(arr[n-1]>sum)
            return solve(arr,sum,n-1);
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i = 0;i<=n;i++)
        {
            for(int j = 0;j<=sum;j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
                if(i>0 and arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
                else if(i>0 and arr[i-1]>j)
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends