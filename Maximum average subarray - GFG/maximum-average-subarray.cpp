// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        // int i = 0,j = 0;
        // int sum = 0;
        // int max_start = 0;
        // int max_avg = 0;
        // while(j<n)
        // {
        //     sum+=arr[j];
        //     if(j-i+1<k)
        //         j++;
        //     else if(j-i+1==k)
        //     {
        //         if(max_avg<=sum)
        //         {
        //             max_avg = sum;
        //             max_start = i;
        //         }
        //         sum-=arr[i++];
        //         j++;
        //     }
        // }
        // return max_start;
        int i=0 ,j=0;
        int ans = INT_MIN;
        int s,e;
        int sum=0;
        while(j<n){
            sum += arr[j];
            if(j-i+1 == k){
                if(ans<=sum){
                    s=i;
                    e=j;
                    ans= sum;
                }
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return s;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends