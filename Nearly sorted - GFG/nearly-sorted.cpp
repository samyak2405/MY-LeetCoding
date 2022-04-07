// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        int i = 0,j = 0;
        K++;
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> res;
        while(j<num)
        {
            pq.push(arr[j]);
            if(j-i+1<K)
                j++;
            else if(j-i+1==K)
            {
                res.push_back(pq.top());
                pq.pop();
                i++;
                j++;
            }
        }
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends