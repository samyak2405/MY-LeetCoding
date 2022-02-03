// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        int i = n-1;
        while(i-1>=0)
        {
            if(arr[i-1]<arr[i])
                break;
            i--;
        }
        if(i==0)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        else
        {
            int j = i;
            for(;j<n;j++)
            {
                if(arr[j]<=arr[i-1])
                    break;
            }
            swap(arr[i-1],arr[j-1]);
            reverse(arr.begin()+i,arr.end());
        }
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends