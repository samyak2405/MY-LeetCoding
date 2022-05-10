// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int n)
	{
	    if(n==1)
	        return 10;
	    map<int,vector<int>> mp;
	    mp[0] = vector<int>{0,8};
	    mp[1] = vector<int>{1,2,4};
	    mp[2] = vector<int>{1,2,3,5};
	    mp[3] = vector<int>{2,3,6};
	    mp[4] = vector<int>{1,4,5,7};
	    mp[5] = vector<int>{2,4,5,6,8};
	    mp[6] = vector<int>{3,5,6,9};
	    mp[7] = vector<int>{4,7,8};
	    mp[8] = vector<int>{0,5,7,8,9};
	    mp[9] = vector<int>{6,8,9};
	    
	    vector<vector<long long>> dp(10,vector<long long>(n+1,1));
	    long long sum = 0;
	    for(int i = 0;i<10;i++)
	    {
	        dp[i][2] = mp[i].size();
	        sum+=mp[i].size();
	    }
	    
	    if(n==2)
	        return sum;
	    sum = 0;
	    
	    for(int i = 3;i<=n;i++)
	    {
	        sum = 0;
	        for(int j = 0;j<10;j++)
	        {
	            long long tmp = 0;
	            for(auto it:mp[j])
	            {
	                tmp+=dp[it][i-1];
	            }
	            dp[j][i] = tmp;
	            sum += tmp;
	        }
	    }
	    return sum;
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends