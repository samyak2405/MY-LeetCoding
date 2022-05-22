// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& pre) {
	    map<int,vector<int>> mp;
	    for(int i = 0;i<pre.size();i++)
	        mp[pre[i].second].push_back(pre[i].first);
	    queue<int> q;
	    vector<int> indegree(n);
	    for(int i = 0;i<pre.size();i++)
	        indegree[pre[i].first]++;
	    for(int i = 0;i<n;i++)
	        if(indegree[i]==0)
	            q.push(i);
	   if(q.empty())
	        return false;
	        
	   while(!q.empty())
	   {
	       int node = q.front();
	       q.pop();
	       for(auto it:mp[node])
	       {
	           indegree[it]--;
	           if(indegree[it]==0)
	            q.push(it);
	       }
	   }
	   for(int i = 0;i<n;i++)
	    if(indegree[i]!=0)
	        return false;
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends