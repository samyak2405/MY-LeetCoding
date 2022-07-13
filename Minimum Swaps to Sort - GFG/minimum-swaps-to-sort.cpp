// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v1;
	    int cnt = 0;
	    int i = 0;
	    int n = nums.size();
	    for(int j = 0;j<n;j++)
	        v1.push_back({nums[j],j});
	    sort(v1.begin(),v1.end());
	    while(i<n)
	    {
	        if(v1[i].second==i)
	            i++;
	        else
	        {
	            cnt++;
	            swap(v1[i],v1[v1[i].second]);
	        }
	    }
	    return cnt;
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
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends