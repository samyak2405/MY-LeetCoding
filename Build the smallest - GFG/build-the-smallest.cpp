// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    string ans = "";
    for(auto it:num)
    {
        while(ans.length() and ans.back()>it and k)
            ans.pop_back(),k--;
        if(ans.length() or it!='0')
            ans.push_back(it);
    }
    while(ans.length() and k)
        ans.pop_back(),k--;
        
    return ans.empty()?"0":ans;
}