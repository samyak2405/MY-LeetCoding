// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
  
    long long f(int n,vector<long long> &dp)
    {
        if(n<=1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        long long res = 0;
        for(int i = 0;i<n;i++)
            res+=f(i,dp)*f(n-i-1,dp);
        return dp[n] = res;
    }
  
    long long dyckPaths(int N) {
        vector<long long> dp(N+1,-1);
        return f(N,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.dyckPaths(N) << endl;
    }
    return 0;
}  // } Driver Code Ends