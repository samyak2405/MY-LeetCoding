// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int ind,int prev,int n,int arr[],vector<vector<int>> &dp)
    {
        if(ind==n)
            return 0;
        if(prev==-1 or abs(arr[prev]-arr[ind])==1)
            return dp[ind][prev+1] = max(1+f(ind+1,ind,n,arr,dp),f(ind+1,prev,n,arr,dp));
        else
            return dp[ind][prev+1] = f(ind+1,prev,n,arr,dp);
    }

    int longestSubsequence(int n, int arr[])
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,n,arr,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends