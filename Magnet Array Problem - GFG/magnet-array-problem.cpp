// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    
    double bs(double l,double h,double magnets[],int n)
    {
        while(l<=h)
        {
            double mid = (l+h)/2;
            double t_force = 0;
            for(int i = 0;i<n;i++)
                t_force +=1/(mid-magnets[i]);
            if(abs(t_force)<0.000001)
                return mid;
            else if(t_force<0)
                h = mid;
            else
                l = mid;
        }
        return l;
    }
    
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        for(int i = 0;i<n-1;i++)
            getAnswer[i] = bs(magnets[i],magnets[i+1],magnets,n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends