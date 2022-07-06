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
	    int n = nums.size();
	    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
	    return f(0,-1,1,nums,dp);
	   // vector<int> lis(n,1),lds(n,1);
	   // for(int i = 1;i<n;i++)
	   // {
	   //     for(int prev = 0;prev<i;prev++)
	   //     {
	   //         if(nums[prev]<nums[i])
	   //             lis[i] = max(lis[i],1+lis[prev]);
	   //     }
	   // }
	   // for(int i = n-2;i>=0;i--)
	   // {
	   //     for(int prev = n-1;prev>=i;prev--)
	   //     {
	   //         if(nums[prev]<nums[i])
	   //             lds[i] = max(lds[i],1+lds[prev]);
	   //     }
	   // }
	   // int ans = 0;
	   // for(int i = 0;i<n;i++)
	   //     ans = max(ans,lis[i]+lds[i]-1);
	   // return ans;
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