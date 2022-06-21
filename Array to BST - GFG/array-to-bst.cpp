// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void helper(vector<int> &nums,vector<int> &res,int low,int high)
    {
        int mid;
        if(low<=high)
        {
            mid = low+(high-low)/2;
            res.push_back(nums[mid]);
            helper(nums,res,low,mid-1);
            helper(nums,res,mid+1,high);
        }
    }

    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> res;
        helper(nums,res,0,nums.size()-1);
        return res;
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends