// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    // int f(int i,int j,int n,int m,string s,string t,vector<vector<int>> &dp)
    // {
    //     if(i>=n)
    //         return 1e9;
    //     if(j>=m)
    //         return 1;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int k = j;
    //     for(;k<m;k++)
    //         if(s[i]==t[k])
    //             break;
    //     if(k==m) return 1;
    //     int not_take = f(i+1,j,n,m,s,t,dp);
    //     int take = 1+f(i+1,k+1,n,m,s,t,dp);
    //     return dp[i][j] = min(take,not_take);
    // }
  
    int shortestUnSub(string S, string T) {
        if(S==T)
            return -1;
        int n = S.length();
        int m = T.length();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return f(0,0,n,m,S,T,dp);
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<=n;i++)
        //     dp[i][0]=1;
        // for(int i=0;i<=m;i++)
        //     dp[0][i]=1e9;
        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = 0;j<m;j++)
        //     {
        //         int k = j;
        //         for(k;k>=0;k--)
        //             if(S[i]==T[k])
        //                 break;
        //         if(k<0)
        //             dp[i+1][j+1] =1;
        //         else
        //             dp[i+1][j+1] = min(dp[i][j+1],1+dp[i][k]);
        //     }
        // }
        // if(dp[n][m]>=1e9)
        //     return -1;
        // return dp[n][m];
        vector<int> prev(m+1,1e9),curr(m+1,1e9);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int k = j;
                for(;k>=0;k--)
                    if(S[i]==T[k])
                        break;
                if(k<0)
                    prev[j+1] = 1;
                else
                    prev[j+1] = min(curr[j+1],1+curr[k]);
            }
            curr = prev;
        }
        if(prev[m]>=1e9)
            return -1;
        return prev[m];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends