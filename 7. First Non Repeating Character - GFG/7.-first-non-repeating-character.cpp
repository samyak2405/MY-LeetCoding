// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

string find(string s);

//Your code will be place here

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int x;
	    cin >> x;
	    string s;
	    cin >> s;
	    int h[26];
	    
	    cout << find(s) << "\n";
	    
	}
	
	return 0;
}// } Driver Code Ends


//User function template for C++

// return the first non-repeating char in S.
// if there's no non-repeating char, return "-1"
string find(string s) {
    unordered_map<char,int> mp;
    for(int i = 0;i<s.length();i++)
        mp[s[i]]++;
    string ans = "";
    for(int i = 0;i<s.length();i++)
    {
        if(mp.find(s[i])->second==1)
        {
            ans = s[i];
            break;
        }
    }
    if(ans.length()==0)
        return "-1";
    return ans;
}