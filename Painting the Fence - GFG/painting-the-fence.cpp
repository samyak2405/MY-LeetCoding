// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // int mod = 1e9+7;
    // long long f(int n,int k,vector<vector<long long>> &dp)
    // {
    //     if(n==1)
    //         return dp[n][k] = k%mod;
    //     if(n==2)
    //         return dp[n][k] = (k%mod+(k*(k-1))%mod)%mod;
    //     return dp[n][k] = (f(n-1,k,dp)%mod + (f(n-2,k,dp)*(k-1))%mod)%mod;
    // }
    
    long long countWays(int n, int k){
        // vector<vector<long long>> dp(n+1,vector<long long>(k+1,-1));
        // return f(n,k,dp);
        int mod = 1e9+7;
        if(n==1)
            return k;
        long long similar_color = k%mod;
        long long diff_color = (k*(k-1))%mod;
        long long total_ways = (diff_color + similar_color)%mod;
        if(n==2)
            return total_ways;
        for(int i = 3;i<=n;i++)
        {
            similar_color = diff_color%mod;
            diff_color = (total_ways*(k-1))%mod;
            total_ways = (similar_color + diff_color)%mod;
        }
        return total_ways;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends