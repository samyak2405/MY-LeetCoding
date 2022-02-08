// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        map<int,vector<int>> mp;
        for(int i = 0;i<n;i++)
        {
            mp[__builtin_popcount(arr[i])].push_back(arr[i]);
        }
        int i = 0;
        for(auto it = mp.rbegin();it!=mp.rend();it++)
        {
            for(auto itr:it->second)
                arr[i++] = itr;
        }
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends