// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> arr){
        vector<int> res;
        
        for(int i = 0;i<N;i++)
        {
            bool flag = false;
            for(int j = N-1;j>i;j--)
            {
                if(arr[i]>arr[j])
                {
                    res.push_back(j);
                    flag = true;
                    break;
                }
            }
            if(!flag)
                res.push_back(-1);
        }
        
        return res;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends