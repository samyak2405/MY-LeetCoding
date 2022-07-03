// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
int maxSumBS(int arr[] , int n );

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
		
		cout<<maxSumBS(a,n)<<endl;
		
	}
}// } Driver Code Ends



int maxSumBS(int arr[] , int n )
{
    int lis[n] = {0},lds[n] = {0};
    for(int i = 0;i<n;i++)
    {
        lis[i] = arr[i];
        int mx = 0;
        for(int prev = 0;prev<i;prev++)
        {
            if(arr[prev]<arr[i])
                mx = max(mx,lis[prev]);
        }
        lis[i] +=mx;
    }
    for(int i = n-1;i>=0;i--)
    {
        lds[i] = arr[i];
        int mx = 0;
        for(int prev = n-1;prev>i;prev--)
        {
            if(arr[prev]<arr[i])
                mx = max(mx,lds[prev]);
        }
        lds[i] +=mx;
    }
    int ans = 0;
    for(int i = 0;i<n;i++)
        ans = max(ans,lis[i] + lds[i]-arr[i]);
    return ans;
}
