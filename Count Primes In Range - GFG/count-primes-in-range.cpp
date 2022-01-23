// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPrimes(int l, int r) {
        int n = r+1;
        int seive[n] = {0};
        
        for(int i = 2;i<n;i++)
            seive[i] = 1;
        
        for(int i = 2;i*i<n;i++)
            if(seive[i])
                for(int j = i*i;j<n;j+=i)
                    seive[j] = 0;
        
        int cnt = 0;
        for(int i = l;i<=r;i++)
            if(seive[i])
                cnt++;
                
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}  // } Driver Code Ends