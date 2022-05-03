// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	
	ll count(int n,vector<ll> &dp,int mod)
	{
	    if(n==1)
	        return dp[n] = 2;
	    if(n==2)
	        return dp[n] = 3;
	    if(dp[n]!=-1)
	        return dp[n];
	    
	    return dp[n] = (count(n-1,dp,mod)+count(n-2,dp,mod))%mod;
	}
	
	ll countStrings(int n) {
	    vector<ll> dp(n+1,-1);
	    return count(n,dp,1e9+7);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends