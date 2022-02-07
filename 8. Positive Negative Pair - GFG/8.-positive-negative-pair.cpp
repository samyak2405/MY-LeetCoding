// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        unordered_set<int> s1;
        vector<int> res;
        
        for(int i = 0;i<n;i++)
        {
            int a = 0-arr[i];
            if(s1.count(a))
            {
                if(a<arr[i])
                {
                    res.push_back(a);
                    res.push_back(arr[i]);
                }
                else
                {
                    
                    res.push_back(arr[i]);
                    res.push_back(a);
                }
            }
            else
                s1.insert(arr[i]);
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
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    }

    return 0;
}  // } Driver Code Ends