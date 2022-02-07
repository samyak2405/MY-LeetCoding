// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        vector<int> seive(N+1,false);
        for(int i = 2;i<N+1;i++)
            seive[i] = true;
        for(int i = 2;i*i<N+1;i++)
            if(seive[i])
                for(int j = i*i;j<N+1;j+=i)
                    seive[j] = false;
        vector<int> res; 
        for(int i = M;i<=N;i++)
            if(seive[i])
                res.push_back(i);
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends