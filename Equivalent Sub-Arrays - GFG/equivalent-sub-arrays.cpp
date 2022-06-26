// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        unordered_set<int> s1;
        for(int i = 0;i<n;i++)
            s1.insert(arr[i]);
        unordered_map<int,int> mp;
        int k = s1.size();
        int start = 0,end = 0,cnt = 0,ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(mp.find(arr[i])==mp.end())
                cnt++;
            mp[arr[i]]++;
            end++;
            if(cnt==k)
                break;
        }
        while(cnt==k)
        {
            while(start<n and cnt==k)
            {
                ans+=n-end+1;
                mp[arr[start]]--;
                if(mp[arr[start]]==0)
                {
                    cnt--;
                    mp.erase(arr[start]);
                }
                start++;
            }
            while(end<n and cnt!=k)
            {
                if(mp.find(arr[end])==mp.end())
                    cnt++;
                mp[arr[end]]++;
                end++;
            }
        }
        return ans;
        
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
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends