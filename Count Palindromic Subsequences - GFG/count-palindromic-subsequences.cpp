// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int mod = 1e9+7;
    /*You are required to complete below method */
    long long int solve(string &str,int i,int j,vector<vector<long long int>> &dp)
    {
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str[i]==str[j])
            return dp[i][j] = (1+solve(str,i+1,j,dp)+solve(str,i,j-1,dp))%mod;
        else
            return dp[i][j] = (mod + solve(str,i+1,j,dp)+solve(str,i,j-1,dp)-solve(str,i+1,j-1,dp))%mod;
    }
    
    long long int  countPS(string str)
    {
        
        int n = str.length();
        vector<vector<long long int>> dp(n,vector<long long int>(n,-1));
        return (solve(str,0,n-1,dp))%mod;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends