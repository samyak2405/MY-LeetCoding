// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        int n = S.length();
        vector<int> prev(256,-1);
        int res = 0;
        int j = 0;
        
        for(int i = 0;i<n;i++)
        {
            j = max(j,prev[S[i]]+1);
            int maxEnd = i - j +1;
            res = max(res,maxEnd);
            prev[S[i]] = i;
        }
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
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends