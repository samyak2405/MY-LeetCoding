// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	int coinchange(vector<int> &nums,vector<int> &dp,int amt)
	{
	    if(amt<0)
	        return -1;
	    if(amt==0)
	        return 0;
	    if(dp[amt]!=0)
	        return dp[amt];
	    int minimum = INT_MAX;
	    for(auto it:nums)
	    {
	        int change = coinchange(nums,dp,amt-it);
	        if(change>=0 and change<minimum)
	            minimum = 1+change;
	    }
	    dp[amt] = (minimum == INT_MAX)?-1:minimum;
	    return dp[amt];
	}
	
	int MinCoin(vector<int>nums, int amt)
	{
	    if(amt<1)
	        return 0;
	   vector<int> dp(amt+1);
	   return coinchange(nums,dp,amt);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends