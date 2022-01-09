// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int maxl[n],maxr[n];
        maxl[0] = arr[0];
        maxr[n-1] = arr[n-1];
        for(int i = 1,j = n-2;i<n,j>=0;i++,j--)
        {
            maxl[i] = max(arr[i],maxl[i-1]);
            maxr[j] = max(arr[j],maxr[j+1]);
        }
        int res[n];
        long long sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum += abs(min(maxl[i],maxr[i]) - arr[i]);
        }
        
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends