// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kPalindrome(string s1, int n, int k)
    {
        if(n==1 or n<=k)
            return 1;
        int dp[n+1][n+1];
        for(int i = 0;i<n+1;i++)
            for(int j = 0;j<n+1;j++)
                    dp[i][j]=0;
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int maxim = INT_MIN;
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<n+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int x = n-dp[n][n];
        return x-k==0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends