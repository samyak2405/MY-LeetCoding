// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long countEvenSum(int arr[], int n) {
        long long even = 0,even_next = 0,odd = 0,odd_next = 0;
        long long sum = 0;
        if(arr[n-1]%2)
            odd = 1;
        else
            even = 1;
        odd_next = odd;
        even_next = even;
        sum+=even;
        for(int i = n-2;i>=0;i--)
        {
            if(arr[i]%2==0)
            {
                even = 1+even_next;
                even_next = even;
            }
            else
            {
                odd = (1+even_next);
                even = odd_next;
                odd_next = odd;
                even_next = even;
            }
            sum+=even;
        }
        return sum;
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
        auto ans = ob.countEvenSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

  // } Driver Code Ends