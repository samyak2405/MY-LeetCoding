// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isDisarium(int n) {
        int x = log10(n)+1;
        int rem = 0;
        int num = n;
        int res = 0;
        while(num)
        {
            int rem = num%10;
            res = res + (int)pow(rem,x--);
            num/=10;
        }
        return res == n;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isDisarium(N) << endl;
    }
    return 0;
}  // } Driver Code Ends