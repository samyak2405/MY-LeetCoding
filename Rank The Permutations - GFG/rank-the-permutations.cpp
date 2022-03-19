// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long fact(long n) 
    { 
        return (n <= 1) ? 1 : n * fact(n - 1); 
    } 
    long long findRank(string S) {
        int n = S.length();
        long long res = 1;
        long long ch = 256;
        long long cnt[ch] = {0};
        long long mul = fact(n);
        for(int i = 0;i<n;i++)
        {
            cnt[S[i]]++;
            if(cnt[S[i]]>1)
                return 0;
        }
        
        for(int i = 1;i<ch;i++)
            cnt[i] += cnt[i-1];
            
        for(int i = 0;i<n-1;i++)
        {
            mul= mul/(n-i);
            res = res + cnt[S[i]-1]*mul;
            for(int j = S[i];j<ch;j++)
                cnt[j]--;
            
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends