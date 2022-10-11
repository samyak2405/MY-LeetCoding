//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        int n = s.length();
        int cnt = 0;
        string ans = "";
        stack<string> s1;
        for(int i = 0;i<n;i++)
        {
            if(s[i]!=']')
            {
                string tmp;
                tmp+=s[i];
                s1.push(tmp);
                continue;
            }
            string curr;
            while(!s1.empty() and s1.top()!="[")
            {
                curr+=s1.top();
                s1.pop();
            }
            s1.pop();
            string count;
            while(!s1.empty() and s1.top()>="0" and s1.top()<="9")
            {
                count+=s1.top();
                s1.pop();
            }
            reverse(count.begin(),count.end());
            cnt = stoi(count);
            string str;
            while(cnt--)
                str+=curr;
            s1.push(str);
        }
        while(!s1.empty())
        {
            ans+=s1.top();
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends