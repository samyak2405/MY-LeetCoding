// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int isPrime(int N){
        if(N==0 or N==1)
        return 0;
        int cnt = 0;
        for(int i = 1;i*i<=N;i++)
        {
            if(!(N%i))
            {
                cnt++;
                if((N/i)!=i)
                    cnt++;
            }
            if(cnt>2)
                return false;
        }
        return true;
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
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends