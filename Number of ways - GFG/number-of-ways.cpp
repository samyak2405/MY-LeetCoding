// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int N){
        long long dp[N+1];
        dp[0]=dp[1]=dp[2]=dp[3]=1;
        dp[4] = 2;
        if(N<=4)
            return dp[N];
        for(int i = 5;i<N+1;i++)
        {
            dp[i] = dp[i-1]+dp[i-4];
        }
        return dp[N];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends