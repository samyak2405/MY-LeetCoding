// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    
    void subset(vector<int> &arr,vector<vector<int>> &res,set<vector<int>> &s1,int ind,vector<int> tmp)
    {
        if(ind==arr.size())
        {
            sort(tmp.begin(),tmp.end());
            if(s1.find(tmp)==s1.end())
            {
                s1.insert(tmp);
                res.push_back(tmp);
            }
            return;
        }
        tmp.push_back(arr[ind]);
        subset(arr,res,s1,ind+1,tmp);
        tmp.pop_back();
        subset(arr,res,s1,ind+1,tmp);
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> res;
        set<vector<int>> s1;
        
        subset(arr,res,s1,0,vector<int>());
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