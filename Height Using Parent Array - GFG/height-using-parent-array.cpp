// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findHeight(int N, int arr[]){
        int _max = INT_MIN,ind = 0;
        for(int i = 0;i<N;i++)
        {
            if(_max<arr[i])
            {
                _max = arr[i];
                ind = i;
            }
        }
        int cnt = 1;
        int i = ind;
        while(arr[i]!=-1)
        {
            cnt++;
            i=arr[i];
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends