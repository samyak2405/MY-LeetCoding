// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int i,int j,vector<vector<int>> &matrix,int n,vector<vector<int>> &dp)
    {
        if(i==n-1)
            return dp[i][j] = matrix[n-1][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int left = INT_MIN,right = INT_MIN,mid = INT_MIN;
        if(j-1>=0)
            left = matrix[i][j] + f(i+1,j-1,matrix,n,dp);
        if(j>=0) 
            mid = matrix[i][j] + f(i+1,j,matrix,n,dp);
        if(j+1<n)
            right = matrix[i][j] +f(i+1,j+1,matrix,n,dp);
        return dp[i][j] = max(right,max(left,mid));
    }

    int maximumPath(int n, vector<vector<int>> matrix)
    {
        int maxi = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i = 0;i<n;i++)
            maxi = max(maxi,f(0,i,matrix,n,dp));
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends