// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> lis(n,1),lds(n,1);
	    for(int i = 1;i<n;i++)
	    {
	        for(int prev = 0;prev<i;prev++)
	        {
	            if(nums[prev]<nums[i])
	                lis[i] = max(lis[i],1+lis[prev]);
	        }
	    }
	    for(int i = n-2;i>=0;i--)
	    {
	        for(int prev = n-1;prev>=i;prev--)
	        {
	            if(nums[prev]<nums[i])
	                lds[i] = max(lds[i],1+lds[prev]);
	        }
	    }
	    int ans = 0;
	    for(int i = 0;i<n;i++)
	        ans = max(ans,lis[i]+lds[i]-1);
	    return ans;
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