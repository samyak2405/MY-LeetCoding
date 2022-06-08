// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    bool isBalanced(string s)
    {
        int open = 0,close = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(')
                open++;
            else
                close++;
            if(close>open)
                return false;
        }
        if(close!=open)
            return false;
        return true;
    }
    
    vector<string> AllParenthesis(int n) 
    {
        string s;
        for(int i = 0;i<n;i++)
            s += '(';
        for(int i = 0;i<n;i++)
            s += ')';
        vector<string> res;
        // int cnt=0;
        do{
            // cout<<s<<" ";
            bool flag = isBalanced(s);
            // cout<<flag<<endl;
            if(flag)
                res.push_back(s);
            // cnt++;
        }while(next_permutation(s.begin(),s.end()));
        // cout<<cnt<<"\n";
        return res;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends