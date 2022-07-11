// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int mod = 1e9+7;
	public:
	
	int f(int ind,int sum,int n,int arr[],vector<vector<int>> &dp)
	{
	    if(sum ==0 and ind==n)
	        return 1;
	    if(ind==n or sum<0)
	        return 0;
	    if(dp[ind][sum]!=-1)
	        return dp[ind][sum];
	    return dp[ind][sum] = (f(ind+1,sum-arr[ind],n,arr,dp)%mod+f(ind+1,sum,n,arr,dp)%mod)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(0,sum,n,arr,dp);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends