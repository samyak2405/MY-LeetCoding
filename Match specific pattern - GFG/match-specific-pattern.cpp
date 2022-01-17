// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict,string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		    cin>>s[i];
		
		string tt;
		cin>>tt;
		
		vector<string> res = findMatchedWords(s,tt);
        sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		    cout<<res[i]<<" ";
		cout<<endl;
		
	}
}// } Driver Code Ends


/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */

bool wordpattern(string s,string t)
{
    if(s.length()!=t.length())
        return false;
    unordered_map<char,int> mp1,mp2;
    for(int i = 0;i<s.length();i++)
    {
        if(mp1[s[i]]!=mp2[t[i]])
            return false;
        mp1[s[i]] = i+1;
        mp2[t[i]] = i+1;
    }
    return true;
}

vector<string> findMatchedWords(vector<string> dict,string pattern)
{
       vector<string> res;
       for(int i = 0;i<dict.size();i++)
       {
           if(wordpattern(dict[i],pattern))
                res.push_back(dict[i]);
       }
       return res;
}