// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
  
    void solve(int index,string s,vector<string> &path,vector<vector<string>> &res)
    {
        if(index==s.length())
        {
            res.push_back(path);
            return;
        }
        for(int i = index;i<s.length();i++)
        {
            if(isPalindrome(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
  
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0,s,path,res);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends