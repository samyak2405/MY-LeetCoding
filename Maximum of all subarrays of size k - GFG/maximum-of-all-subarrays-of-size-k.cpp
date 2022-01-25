// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> res;
        
        int i = 0,j = 0;
        int max_val = INT_MIN;
        while(j<n)
        {
            if(j-i+1<k)
            {
                max_val = max(max_val,arr[j]);
                j++;
            }
            else if(j-i+1==k)
            {
                if(arr[j]>max_val)
                    max_val = arr[j];
                res.push_back(max_val);
                if(max_val == arr[i])
                    max_val = *max_element(arr+i+1,arr+i+1+k);
                i++;
                j++;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends