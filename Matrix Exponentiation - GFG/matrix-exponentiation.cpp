// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int mod =1e9+7;
public:

    using ll = long long;

    ll mul(ll a,ll b)
    {
        return ((a%mod)*(b%mod))%mod;
    }
    
    ll add(ll a,ll b)
    {
        return ((a%mod)+(b%mod))%mod;
    }

    pair<int,int> fib(long long int n)
    {
        if(n==0)
            return {0,1};
        auto p = fib(n>>1);
        int c = mul(p.first,(mul(2,p.second)-p.first)+mod)%mod;
        int d = add(mul(p.first,p.first),mul(p.second,p.second));
        if(n&1)
            return {d,(c+d)%mod};
        else
            return {c,d};
    }
    

    int FindNthTerm(long long int n) {
        pair<int,int> p = fib(n);
        return p.second;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends