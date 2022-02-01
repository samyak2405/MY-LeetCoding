// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:

    int solve(int n)
    {
        int res = 0, rem = 0;
        while(n>0)
        {
            rem = n%10;
            res+=rem*rem;
            n/=10;
        }
        return res;
    }

    int isHappy(int n){
        while(n!=1 and n!=4)
        {
            n = solve(n);
        }
        if(n==4)
            return 0;
        return 1;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends