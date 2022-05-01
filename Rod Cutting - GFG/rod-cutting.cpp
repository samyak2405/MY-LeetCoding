// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        int len = n;
        vector<int> curr(len+1,0),prev(n+1,0);
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<len+1;j++)
            {
                if(i<=j)
                    curr[j] = max(curr[j-i]+price[i-1],prev[j]);
                else 
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return curr[len];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends