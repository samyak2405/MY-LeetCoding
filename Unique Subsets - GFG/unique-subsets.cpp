// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    
    void subset(vector<int> &arr,vector<vector<int>> &res,int ind,vector<int> curr)
    {
        if(ind>=arr.size())
        {
            res.push_back(curr);
            return;
        }
        int currind = ind+1;
        while(currind<arr.size() and arr[currind]==arr[ind])
            currind++;
        int cnt = currind-ind;
        for(int i = 0;i<=cnt;i++)
        {
            for(int j = 0;j<i;j++)
            {
                curr.push_back(arr[ind]);
            }
            
            subset(arr,res,currind,curr);
            
            for(int j = 0;j<i;j++)
            {
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        
        subset(arr,res,0,vector<int>());
        
        sort(res.begin(),res.end());
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
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
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
}   


  // } Driver Code Ends