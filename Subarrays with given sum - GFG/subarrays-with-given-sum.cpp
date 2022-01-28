// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int subArraySum(int arr[], int n, int sum)
    {
    	int cnt = 0;
    	map<int,int> mp;
    	int curr_sum = 0;
    	for(int i = 0;i<n;i++)
    	{
    	    curr_sum+=arr[i];
    	    if(curr_sum == sum)
    	    {
    	        cnt++;
    	    }
    	    if(mp.find(curr_sum-sum)!=mp.end())
    	    {
    	        cnt+=mp[curr_sum-sum];
    	    }
    	    mp[curr_sum]++;
    	}
    	return cnt;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution ob;
	    cout<<ob.subArraySum(arr, n, sum);
	    cout<<'\n';
	}
	return 0;
}  // } Driver Code Ends