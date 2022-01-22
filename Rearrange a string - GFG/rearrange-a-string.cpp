// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        string res = "";
        int sum = 0;
        int cnt[26] = {0};
        for(int i = 0;i<str.length();i++)
        {
            if(str[i]>='0' and str[i]<='9')
                sum+=str[i]-'0';
            else{
                cnt[str[i]-'A']++;
            }
        }
        for(int i = 0;i<26;i++)
            if(cnt[i]!=0)
                {
                    while(cnt[i]--)
                    {
                        res+=('A'+i);
                    }
                }
        res+=to_string(sum);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends