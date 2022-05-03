// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    
	    ll a = 2;
	    if(n==1)
	        return a;
	    ll b = 3;
	    if(n==2)
	        return b;
	    int mod = 1e9+7;
	    ll c;
	    for(int i = 3;i<=n;i++)
	    {
	        c = (a+b)%mod;
	        a = b;
	        b = c;
	    }
	    return c;
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