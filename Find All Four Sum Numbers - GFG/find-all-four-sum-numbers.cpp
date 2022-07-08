// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> res;
        if(arr.size()<=3)
            return res;
        sort(arr.begin(),arr.end());
        for(int i = 0;i<arr.size();i++)
        {
                int sum = k-arr[i];
                for(int j = i+1;j<arr.size();j++)
                {
                    int sum1 = sum - arr[j];
                    int k = j+1,l = arr.size()-1;
                    while(k<l)
                    {
                        int a = arr[k];
                        int b = arr[l];
                        if(a+b==sum1)
                        {
                            res.push_back({arr[i],arr[j],arr[k],arr[l]});
                            do{k++;}while(k<l and a==arr[k]);
                            do{l--;}while(k<l and b==arr[l]);
                        }
                        else if(a+b<sum1)
                            k++;
                        else
                            l--;
                    }
                    while(j+1<arr.size() and arr[j]==arr[j+1])
                        j++;
                }
                while(i+1<arr.size() and arr[i]==arr[i+1])
                    i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends