// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int i = 0,j = 0,x = 0,y = INT_MAX;
        string res = "";
        unordered_map<char,int> mp;
        
        for(auto it:p)
            mp[it]++;
        int cnt = mp.size();
        if(mp.find(s[j])!=mp.end())
        {
            mp[s[j]]--;
            if(mp[s[j]]==0)
                cnt--;
        }
        
        while(j<s.length())
        {
            if(cnt>0)
            {
                j++;
                if(mp.find(s[j])!=mp.end())
                {
                    mp[s[j]]--;
                    if(mp[s[j]]==0)
                        cnt--;
                }
            }
            else if(cnt==0)
            {
                if(y>j-i+1)
                {
                    y = j-i+1;
                    x = i;
                }
            }
            while(cnt==0)
            {
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                    {
                        cnt++;
                        if(y>j-i+1)
                        {
                            y = j-i+1;
                            x = i;
                        }
                    }
                }
                i++;
            }
        }
        
        if(y==INT_MAX)
            return "-1";
        return res.append(s.substr(x,y));
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends