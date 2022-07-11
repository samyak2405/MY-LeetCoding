// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> nos;
        for(int i = 1;i<n;i++)
        {
            fact = fact*i;
            nos.push_back(i);
        }
        nos.push_back(n);
        string ans = "";
        k--;
        while(1)
        {
            ans+=to_string(nos[k/fact]);
            nos.erase(nos.begin()+k/fact);
            if(nos.size()==0)
                return ans;
            k = k%fact;
            fact = fact/nos.size();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends