// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string s){
        string srev = s;
        reverse(srev.begin(),srev.end());
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<n+1;j++)
            {
                if(i==0 or j==0)
                    dp[i][j] = 0;
                else if(s[i-1]==srev[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return s.length()-dp[n][n];
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends