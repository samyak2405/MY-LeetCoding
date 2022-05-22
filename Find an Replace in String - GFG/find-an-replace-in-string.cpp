// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    string findAndReplace(string s ,int q, int index[], string sources[], string targets[]) {
        vector<pair<int,int>> vc;
        for(int i = 0;i<q;i++)
        {
            if(s.find(sources[i],index[i])==index[i])
                vc.push_back({index[i],i});
        }
        sort(vc.begin(),vc.end(),greater<pair<int,int>>());
        for(auto it:vc)
        {
            s.replace(s.find(sources[it.second],it.first),sources[it.second].length(),targets[it.second]);
        }
        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends