// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    int bellNumber(int n)
    {
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        dp[0][0] = 1;
        int mod = 1e9+7;
        for(int i =1;i<n+1;i++)
        {
            for(int j = 0;j<=i;j++)
            {
                if(j==0)
                    dp[i][j] = dp[i-1][i-1];
                else
                    dp[i][j] = (dp[i-1][j-1]+dp[i][j-1])%mod;
            }
        }
        // for(int i = 0;i<n+1;i++)
        // {
        //     for(int j = 0;j<n+1;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][0];
    }
};


// { Driver Code Starts.



int main()
{
    Solution obj;
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<obj.bellNumber(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends