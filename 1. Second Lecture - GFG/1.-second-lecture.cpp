#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll res = (2*n+1)/3;
	    if((2*n+1)%3==0)
	        cout<<"YES "<<res;
	    else
	        cout<<"NO";
	    cout<<"\n";
	}
	return 0;
}