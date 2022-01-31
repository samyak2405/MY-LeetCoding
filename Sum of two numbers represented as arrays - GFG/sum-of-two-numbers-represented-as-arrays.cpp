// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    int i = 0,j=0;
	    int c = 0;
	    reverse(a.begin(),a.end());
	    reverse(b.begin(),b.end());
	    while(i<a.size() or j<b.size())
	    {
	        c+=i<a.size()?a[i]:0;
	        c+=j<b.size()?b[j]:0;
	        
	        if(i<a.size())
	            a[i] = c%10;
	        else
	            a.push_back(c%10);
	        c = c>=10?1:0;
	        i++;
	        j++;
	    }
	    if(c==1)
	        a.push_back(1);
	    reverse(a.begin(),a.end());
	    return a;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends