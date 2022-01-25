// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    static bool sortby(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second<b.second;
    }
    
    vector<int> TopK(vector<int>& arr, int k)
    {
        map<int,int> mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        
        priority_queue<pair<int,int>>  q;
        
        for(auto it:mp)
        {
            q.push({it.second,it.first});
        }
        
        vector<int> res;
        
        while(k-- and !q.empty())
        {
            res.push_back(q.top().second);
            q.pop();
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends