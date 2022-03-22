// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        map<int,vector<int>> mp;
        for(int i = 0;i<mat.size();i++)
        {
            vector<int> tmp;
            for(int j = 0;j<mat[i].size();j++)
                mp[i+j].emplace_back(mat[i][j]);
        }
            
        vector<int> res;
        for(auto it: mp)
        {
            vector<int> tmp = it.second;
            if(it.first%2==0)
                reverse(tmp.begin(),tmp.end());
            for(auto itr:tmp)
                res.emplace_back(itr);
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}  // } Driver Code Ends