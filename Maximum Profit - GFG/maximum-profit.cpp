// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int i = n-1;i>=0;i--)
        {
            int profit = 0;
            for(int j = 0;j<2;j++)
            {
                for(int l = 1;l<k+1;l++)
                {
                    if(j)
                        profit = max(-prices[i] + dp[i+1][0][l],dp[i+1][1][l]);
                    else
                        profit = max(prices[i] + dp[i+1][1][l-1],dp[i+1][0][l]);
                    dp[i][j][l] = profit;
                }
            }
        }
        return dp[0][1][k];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends