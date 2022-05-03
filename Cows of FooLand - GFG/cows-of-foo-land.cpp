// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    
    long long int f(long long int n,long long int &next,int mod)
    {
        if(n==0)
        {
            next =1;
            return 0;
        }
        long long int nb2p1;
        long long int nb2 = f(n/2,nb2p1,mod);
        long long int a = (nb2*((2*nb2p1)-nb2))%mod;
        if(a<0)
            a += mod;
        long long int b = ((nb2p1*nb2p1)+(nb2*nb2))%mod;
        if(n%2==0)
        {
            next = b;
            return a;
        }
        else
        {
            next = (a+b)%mod;
            return b;
        }
    }
	
	
	int TotalAnimal(long long int n){
	    long long int next;
	    int mod = 1e9+7;
	    f(n,next,mod);
	    return next;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalAnimal(N);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends