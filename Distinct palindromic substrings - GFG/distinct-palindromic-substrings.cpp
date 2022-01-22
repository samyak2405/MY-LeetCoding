// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
  
    void solve(string s,int l,int r,set<string> &s1)
    {
        int n = s.length();
        while(l>=0 and r<n)
            {
                if(s[l]==s[r])
                {
                    s1.insert(s.substr(l,r-l+1));
                    l--;
                    r++;
                }
                else
                    break;
            }
        return;
    }
    
    int palindromeSubStrs(string s) {
        int n = s.length();
        set<string> s1;
        for(int i = 0;i<n;i++)
            solve(s,i,i,s1);
        for(int i = 0;i<n-1;i++)
            solve(s,i,i+1,s1);
        return s1.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends