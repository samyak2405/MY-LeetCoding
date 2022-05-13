// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  
    bool subset(int a[],int n,vector<bool> &vis,int start,int k,int sum,int target)
    {
        if(k==0)
            return true;
        if(sum>target)
            return false;
        if(sum==target)
            return subset(a,n,vis,0,k-1,0,target);
        for(int i = start;i<n;i++)
        {
            if(vis[i])
                continue;
            vis[i] = true;
            if(subset(a,n,vis,i+1,k,sum+a[i],target))
                return true;
            vis[i] = false;
        }
        return false;
    }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum =0;
        for(int i = 0;i<n;i++)
            sum+=a[i];
        if(sum%k)
            return false;
        sum/=k;
        if(n<k)
            return false;
        vector<bool> vis(n,0);
        return subset(a,n,vis,0,k,0,sum);
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
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends