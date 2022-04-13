// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amt)
	{
	    vector<int> dp(amt+1,amt+1);
	    sort(nums.begin(),nums.end());
	    dp[0] = 0;
	    for(int i = 1;i<amt+1;i++)
	        for(int j = 0;j<nums.size() and nums[j]<=i;j++)
	                dp[i] = min(dp[i],dp[i-nums[j]]+1);
	    return (dp[amt]==amt+1)?-1:dp[amt];
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