// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int sum) 
    { 
        int curr_sum = 0;
        map<int,int> mp;
        int res = 0;

        for(int i = 0;i < n;i++)
        {
            curr_sum += arr[i];
            if(curr_sum-sum==0)
            {
                res = max(res,i+1);
            }
            if(mp.find(curr_sum-sum)!=mp.end())
            {
                res = max(res,i-mp[curr_sum-sum]);
            }
            if(mp.find(curr_sum)==mp.end())
                mp[curr_sum] = i;
        }
        
        return res;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends