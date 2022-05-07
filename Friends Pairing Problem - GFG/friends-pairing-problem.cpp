// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    long long f(int i,vector<long long> &dp,int &mod)
    {
        if(i<=0)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        long long v1 = f(i-1,dp,mod)%mod;
        long long v2 = ((i-1)*f(i-2,dp,mod))%mod;
        return dp[i]=(v1+v2)%mod;
    }

    int countFriendsPairings(int n) 
    { 
        int mod = 1e9+7;
        vector<long long> dp(n+1,-1);
        return f(n,dp,mod);
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends