// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int i,int j,bool istrue,string s,vector<vector<vector<int>>> &dp,int mod)
    {
        if(i>j)
            return 0;
        if(i==j)
        {
            if(istrue==1)
                return dp[i][j][istrue] = s[i]=='T';
            else
                return dp[i][j][istrue] = s[i]=='F';
        }
        if(dp[i][j][istrue]!=-1)
            return dp[i][j][istrue];
        int ans = 0;
        
        for(int k = i+1;k<=j-1;k+=2)
        {
            int lt = f(i,k-1,1,s,dp,mod);
            int lf = f(i,k-1,0,s,dp,mod);
            int rt = f(k+1,j,1,s,dp,mod);
            int rf = f(k+1,j,0,s,dp,mod);
            
            if(s[k]=='&')
            {
                if(istrue==1)
                    ans = (ans + (lt*rt)%mod)%mod;
                else
                    ans = (ans + (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod; 
            }
            else if(s[k]=='|')
            {
                if(istrue==1)
                    ans = (ans +(lt*rf)%mod + (lf*rt)%mod + (lt*rt)%mod)%mod;
                else
                    ans = (ans + (lf*rf)%mod)%mod;
            }
            else if(s[k]=='^')
            {
                if(istrue==1)
                    ans = (ans + (lt*rf)%mod + (lf*rt)%mod)%mod;
                else
                    ans = (ans + (lt*rt)%mod + (lf*rf)%mod)%mod;
            }
        }
        return dp[i][j][istrue] = ans;
    }

    int countWays(int n, string s){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int mod = 1003;
        return f(0,n-1,1,s,dp,mod);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends