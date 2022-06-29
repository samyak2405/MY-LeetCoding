// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string res = arr[0];
        for(int i = 1;i<N;i++)
            if(res.length()>arr[i].length())
                res = arr[i];
        int ans = res.size();
        
        for(int i = 0;i<N;i++)
        {
            
            int cnt = 0;
            if(res==arr[i])
                cnt = res.size();
            else
            {
                int j = 0;
                int k = 0;
                while(res[j]==arr[i][k])
                {
                    cnt++;
                    j++;
                    k++;
                }
                }
            
            if(cnt==0)
                return "-1";
            ans = min(ans,cnt);
        }
        return res.substr(0,ans);
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends