// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    int distinct(string s,int l,int r)
    {
        unordered_set<char> s1;
        // cout<<l<<" "<<r<<endl;
        for(int i = l;i<=r;i++)
        {
            s1.insert(s[i]);
        }
        return s1.size();
    }

	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    vector<int> res;
	    for(int i = 0;i<Query.size();i++)
	        res.push_back(distinct(str,Query[i][0]-1,Query[i][1]-1));
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends