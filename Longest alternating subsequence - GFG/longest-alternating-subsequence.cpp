// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
	   // int f(int ind,int prev,int flag,vector<int> &nums,vector<vector<vector<int>>> &dp)
	   // {
	   //     if(ind==nums.size())
	   //         return 0;
	   //     if(dp[ind][prev+1][flag]!=-1)
	   //         return dp[ind][prev+1][flag];
	   //     int nt = f(ind+1,prev,flag,nums,dp);
	   //     int t = 0;
	   //     if(prev==-1)
	   //         t = 1+ f(ind+1,ind,1-flag,nums,dp);
	   //     else
	   //     {
	   //         if(!flag and nums[ind]>nums[prev])
	   //             t = 1+f(ind+1,ind,1-flag,nums,dp);
	   //         else if(flag and nums[ind]<nums[prev])
	   //             t = 1+f(ind+1,ind,1-flag,nums,dp);
	   //     }
	   //     return dp[ind][prev+1][flag] = max(t,nt);
	   // }
	
		int AlternatingaMaxLength(vector<int>&nums){
		  int n = nums.size();
		  //  vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
		  //  return max(f(0,-1,0,nums,dp),f(0,-1,1,nums,dp));
		  int up = 1;
		  int down = 1;
		  for(int i  =1;i<n;i++)
		  {
		      if(nums[i]<nums[i-1])
		        down = up+1;
		       else if(nums[i]>nums[i-1])
		        up = down+1;
		  }
		  return max(up,down);
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
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends