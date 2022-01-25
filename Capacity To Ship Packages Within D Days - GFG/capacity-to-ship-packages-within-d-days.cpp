// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int solve(int arr[],int cap,int N)
    {
        int sum  =0;
        int cnt = 1;
        for(int i = 0;i<N;i++)
        {
            if(arr[i]>cap)
                return INT_MAX;
            if(sum+arr[i]<=cap)
                sum+=arr[i];
            else
            {
                sum = arr[i];
                cnt++;
            }
        }
        return cnt;
    }
  
    int leastWeightCapacity(int arr[], int N, int D) {
        int low = 1,high = 1e9;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            int d = solve(arr,mid,N);
            if(d<=D)
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends