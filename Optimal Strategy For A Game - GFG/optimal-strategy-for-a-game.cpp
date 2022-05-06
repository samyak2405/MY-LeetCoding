// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long f(int i,int j,int arr[],int n,vector<vector<long long>> &dp)
    {
        if(i>j)
            return 0;
        if(i==j)
            return dp[i][j] = arr[i];
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        long long int front_pick = arr[i] + min(f(i+2,j,arr,n,dp),f(i+1,j-1,arr,n,dp));
        long long int back_pick = arr[j] + min(f(i+1,j-1,arr,n,dp),f(i,j-2,arr,n,dp));
        return dp[i][j] = max(front_pick,back_pick);
    }
    
    long long maximumAmount(int arr[], int n){
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        return f(0,n-1,arr,n,dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends