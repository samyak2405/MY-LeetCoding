// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
            int res = 0;
            
            int tmp[n];
            for(int i = 0;i<n;i++)
                tmp[i] = arr1[i]-arr2[i];
            unordered_map<int,int> mp;
            int sum = 0;
            for(int i = 0;i<n;i++)
            {
                sum+=tmp[i];
                if(sum==0)
                    res= max(res,i+1);
                if(mp.find(sum)!=mp.end())
                    res = max(res,i-mp[sum]);
                if(mp.find(sum)==mp.end())
                    mp[sum] = i;
            }
            return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends