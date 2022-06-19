// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    int f(int n,int x,int y,int z,vector<int> &dp)
    {
        if(n<0)
            return -1e9;
        if(n==0)
            return dp[n] = 0;
        if(dp[n]!=-1)
            return dp[n];
        int v1 = f(n-x,x,y,z,dp);
        int v2 = f(n-y,x,y,z,dp);
        int v3 = f(n-z,x,y,z,dp);
        return dp[n] = 1+max(v1,max(v2,v3));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int res = f(n,x,y,z,dp);
        return res<0?0:res;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends