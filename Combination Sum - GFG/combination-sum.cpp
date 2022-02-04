// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void solve(vector<int> &nums,int index,int target,vector<vector<int>> &res,vector<int> &tmp)
    {
        
        if(target==0)
        {
            res.push_back(tmp);
            return;
        }
        
        for(int i = index;i!=nums.size() and target>=nums[i];i++)
        {
            tmp.push_back(nums[i]);
            solve(nums,i,target-nums[i],res,tmp);
            tmp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        set<int> nums1;
        for(auto it:nums)
            nums1.insert(it);
        nums.clear();
        for(auto it:nums1)
            nums.push_back(it);
        solve(nums,0,target,res,tmp);
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends