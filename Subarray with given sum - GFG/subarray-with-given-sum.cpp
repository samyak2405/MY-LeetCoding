// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long sum)
    {
        vector<int> res;
        int i = 0,j = 0;
        long long s = 0;
        
        while(j<n)
        {
            s+=arr[j];
            if(s<sum)
            {
                j++;
            }
            else if(s==sum)
                break;
            else if(s>sum)
            {
                while(s>sum)
                {
                    s-=arr[i];
                    i++;
                }
                if(s==sum)
                    break;
                else
                    j++;
            }
        }
        
        
        if(j>=n)
            return vector<int>(1,-1);
        return vector<int>{i+1,j+1};
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends