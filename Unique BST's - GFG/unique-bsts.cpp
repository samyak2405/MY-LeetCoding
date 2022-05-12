// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return the total number of possible unique BST.
    
    long long f(int n,vector<long long> &dp,int mod)
    {
        if(n<=1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        long long res = 0;
        for(int i = 0;i<n;i++)
        {
            res = (res +(f(i,dp,mod)*f(n-i-1,dp,mod))%mod)%mod;
        }
        return dp[n] = res;
    }
    
    int numTrees(int N) 
    {
        int mod = 1e9+7;
        vector<long long> dp(N+1,-1);
        return f(N,dp,mod);
    }
};

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends