// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
    int mod = 1e9+7;
  public:
    // s : given string
    // return the expected answer
    
    int fun(string &s) {
        long long mod = 1e9+7,a = 0,ab = 0,abc = 0;
        
        for(auto it:s)
        {
            if(it=='a')
                a = (2*a+1)%mod;
            else if(it=='b')
                ab = (2*ab+a)%mod;
            else
                abc = (2*abc + ab)%mod;
        }
        return abc;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends