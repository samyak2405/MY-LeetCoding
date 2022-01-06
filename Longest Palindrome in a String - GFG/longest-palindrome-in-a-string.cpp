// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  
    void solve(string s,int l,int r,int &max_len,int &st)
    {
        while(l>=0 and r<s.length())
        {
            if(s[l]==s[r])
            {
                l--;
                r++;
            }
            else
                break;
        }
        int len = r-l-1;
        if(len>max_len)
        {
            max_len = len;
            st = l+1;
        }
    }
  
    string longestPalin (string s) {
        if(s.length()<2)
            return s;
        int st = 0;
        int n = s.length();
        int max_len = 1;
        for(int i = 0;i<n-1;i++)
        {
            solve(s,i,i,max_len,st);
            solve(s,i,i+1,max_len,st);
        }
        
        return s.substr(st,max_len);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends