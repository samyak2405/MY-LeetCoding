// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x==0 or x==1)
            return x;
        long long int low = 0,high = x;
        long long int fl = -1;
        while(low<=high)
        {
            long long int mid = low+int(high-low)/2;
            if(mid == int(x/mid))
                return mid;
            if(mid<int(x/mid))
            {
                fl = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return fl;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends