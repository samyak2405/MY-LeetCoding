// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  
    vector<int> solve(int arr[],int n,int sum)
    {
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i = 0;i<n+1;i++)
            dp[i][0] = 1;
        
        for(int i =1;i<n+1;i++)
        {
            for(int j = 1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n];
    }
  
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i = 0;i<n;i++)
	        sum+=arr[i];
	    
	    vector<int> tmp = solve(arr,n,sum);
	    
	    int res = INT_MAX;
	   // for(auto it:tmp)
	   //     cout<<it<<" ";
	        
	    for(int i = 1;i<tmp.size();i++)
	    {
	        if(tmp[i]==1)
	            res = min(res,abs(sum-2*i));
	    }
	    return res;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends