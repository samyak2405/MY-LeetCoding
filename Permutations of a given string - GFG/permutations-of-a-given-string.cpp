// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
        	
	    void solve(string s,int index,vector<string> &res)
	    {
	        if(index>=s.length())
	       {
	           res.push_back(s);
	           return;
	       }
	       for(int i = index;i<s.length();i++)
	       {
	           swap(s[i],s[index]);
	           solve(s,index+1,res);
	           swap(s[i],s[index]);
	       }
	    }
	
		vector<string> find_permutation(string S)
		{
		    vector<string> res;
		    sort(S.begin(),S.end());
		    solve(S,0,res);
		    sort(res.begin(),res.end());
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends