// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        queue<char> q;
        string res;
        q.push('$');
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                if(q.front()=='$')
                {
                    res+="0.";
                    
                }   
                else
                {
                    while(!q.empty())
                    {
                        res+=q.front();
                        q.pop();
                    }
                    res+='.';
                    q.push('$');
                }
            }
            else if(s[i]=='0' and q.front()=='$')
                continue;
            else
            {
                if(q.front()=='$')
                    q.pop();
                q.push(s[i]);
            }
        }
        if(q.front()=='$')
        {
            res+='0';
        }
        else
        {
            while(!q.empty())
            {
                res+=q.front();
                q.pop();
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends