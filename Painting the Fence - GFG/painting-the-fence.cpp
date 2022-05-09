// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        int mod = 1e9+7;
        if(n==1)
            return k;
        long long same = k%mod;
        long long diff = (k*(k-1))%mod;
        long long total = (diff + same)%mod;
        for(int i = 3;i<=n;i++)
        {
            same = diff%mod;
            diff = (total*(k-1))%mod;
            total = (same + diff)%mod;
        }
        return total;
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