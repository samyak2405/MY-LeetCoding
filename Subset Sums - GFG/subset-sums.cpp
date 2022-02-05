// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void solve(vector<int> &arr,int sum,vector<int> &res,int index)
    {
        if(index==arr.size())
        {
            res.push_back(sum);
            return;
        }
        solve(arr,sum+arr[index],res,index+1);
        solve(arr,sum,res,index+1);
        return;
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        solve(arr,0,res,0);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends