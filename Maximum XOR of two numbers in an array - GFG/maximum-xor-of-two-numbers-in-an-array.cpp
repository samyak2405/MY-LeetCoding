// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        int maxi = 0;
        int mask = 0;
        
        for(int i = 30;i>=0;i--)
        {
            set<int> s1;
            
            mask |= (1<<i);
            
            for(int j = 0;j<n;j++)
                s1.insert(mask&arr[j]);
                
            int newmax = maxi|(1<<i);
            
            for(int prefix:s1)
            {
                if(s1.count(newmax^prefix))
                {
                    maxi = newmax;
                    break;
                }
            }
        }
        return maxi;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}


  // } Driver Code Ends