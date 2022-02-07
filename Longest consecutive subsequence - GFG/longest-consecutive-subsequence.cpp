// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_set<int> mp;
        for(int i = 0;i<n;i++)
            mp.insert(arr[i]);
        int res = 1;
        for(int i = 0;i<n;i++)
        {
            if(mp.find(arr[i]-1)==mp.end())
            {
                int cnt = 1;
                while(mp.find(arr[i]+cnt)!=mp.end())
                    cnt++;
                res = max(res,cnt);
            }
        }
        return res;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends