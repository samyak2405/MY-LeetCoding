// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    int l = 0,r = n-1;
	    if(nums[l]<=nums[r])
	        return 0;
	    while(l<r and nums[l]>=nums[r])
	    {
	        int mid = l+(r-l)/2;
	        if(nums[mid]>nums[r])
	            l = mid+1;
	       else if(nums[mid]<nums[l])
	            r = mid,l++;
	       else
	            r--;
	    }
	    return l;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends