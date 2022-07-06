// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        sort(A,A+N);
        int ans = A[0] + A[1] + A[2];
        for(int i = 0;i<N;i++)
        {
            int j = i+1,k=N-1;
            while(j<k)
            {
                int sum = A[i]+A[j]+A[k];
                if(sum==X)
                    return sum;
                if(abs(sum-X)<=abs(ans-X))
                    ans = sum;
                if(sum<X)
                    j++;
                else
                    k--;
            }
        }
        return ans;
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
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}  // } Driver Code Ends