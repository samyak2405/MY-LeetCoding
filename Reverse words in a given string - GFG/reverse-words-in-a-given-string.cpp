// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        vector<string> v1;
        string temp,res="";
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                v1.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        v1.push_back(temp);
        
        
        for(int i = v1.size()-1;i>=0;i--)
            res+=v1[i]+".";
        
        res.pop_back();
        return res;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends