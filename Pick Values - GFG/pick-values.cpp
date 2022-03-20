// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int pickValues(int arr[], int n) {
        // if(n==1)
        //     return arr[0];
        // if(n==2)
        //     return min(arr[0],arr[1]);
        // if(n==3)
        //     return min({arr[0],arr[1],arr[2]});
        int dp[n];
        for(int i =0;i<n;i++)
        {
            if(i==0 or i==1 or i==2 or i==3)
                dp[i] = arr[i];
            else
                dp[i] = min({dp[i-1],dp[i-2],dp[i-3],dp[i-4]})+arr[i];
        }
        return min({dp[n-1],dp[n-2],dp[n-3],dp[n-4]});
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.pickValues(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


  // } Driver Code Ends