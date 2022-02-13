// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       int _xor = 0;
       int *res = new int[2];
       
        for(int i = 0;i<n;i++)
            _xor^=arr[i]^(i+1);
        
        int rsb = _xor&-_xor;
        
        int x = 0;
        int y = 0;
        
        for(int i = 0;i<n;i++)
        {
            if(rsb&arr[i])
                x^=arr[i];
            else
                y^=arr[i];
        }
        
        for(int i = 1;i<=n;i++)
        {
            if(rsb&i)
                x^=i;
            else
                y^=i;
        }
        bool flag = false;
        for(int i = 0;i<n;i++)
        {
            if(x == arr[i])
            {
                res[0] = x;
                flag = true;
                break;
            }
        }
        if(flag)
            res[1] = y;
        else
        {
            res[0] = y;
            res[1] = x;
        }
       return res;
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends