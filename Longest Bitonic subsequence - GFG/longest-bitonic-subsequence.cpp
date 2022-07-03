// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	int f(int ind,int prev,int flag,vector<int> &nums,vector<vector<vector<int>>> &dp)
	{
	    if(ind==nums.size())
	        return 0;
	    if(dp[ind][prev+1][flag]!=-1)
	        return dp[ind][prev+1][flag];
	    int nt = f(ind+1,prev,flag,nums,dp);
	    int t = 0;
	    if(prev==-1)
	        t = 1+f(ind+1,ind,flag,nums,dp);
	    else
	    {
	        if(flag)
	        {
	            if(nums[ind]>nums[prev])
	                t = 1+f(ind+1,ind,flag,nums,dp);
	            else if(nums[ind]<nums[prev])
	                t = 1+f(ind+1,ind,1-flag,nums,dp);
	        }
	        else
	        {
	            if(nums[ind]<nums[prev])
	                t = 1+f(ind+1,ind,flag,nums,dp);
	        }
	    }
	    return dp[ind][prev+1][flag] = max(t,nt);
	}
	
 	int LongestBitonicSequence(vector<int>nums)
	{
	    vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
	    return f(0,-1,1,nums,dp);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends