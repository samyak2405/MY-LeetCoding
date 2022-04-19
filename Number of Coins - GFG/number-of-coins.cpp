// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int amt) 
	{ 
	    sort(coins,coins+n);
	    vector<int> dp(amt+1,amt+1);
	    dp[0] = 0;
	    for(int i = 1;i<amt+1;i++)
	    {
	        for(int j = 0;j<n;j++)
	        {
	            if(coins[j]<=i)
	                dp[i] = min(dp[i],dp[i-coins[j]]+1);
	        }
	    }
	    return dp[amt]==amt+1?-1:dp[amt];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends