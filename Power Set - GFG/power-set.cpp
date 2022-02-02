// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n = s.length();
		    vector<string> res;
		    for(int num = 0;num<=(pow(2,n)-1);num++)
		    {
		        string str = "";
		        for(int i = 0;i<n;i++)
		        {
		            if(num&(1<<i))
		            {
		                str+=s[i];
		            }
		        }
		        if(str!="")
		        res.push_back(str);
		    }
		    sort(res.begin(),res.end());
		    return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends