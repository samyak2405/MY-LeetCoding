// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
  
    // long long f(int n,vector<long long> &dp)
    // {
    //     if(n<=1)
    //         return 1;
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     long long res = 0;
    //     for(int i = 0;i<n;i++)
    //         res+=f(i,dp)*f(n-i-1,dp);
    //     return dp[n] = res;
    // }
  
    long long dyckPaths(int N) {
        // vector<long long> dp(N+1,-1);
        // return f(N,dp);
        if(N==0 or N==1 )
            return N;
        vector<long long> dp(N+1,0);
        dp[0]=dp[1] =1;
        for(int i = 2;i<=N;i++)
        {
            for(int j = 0;j<i;j++)
            {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[N];
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