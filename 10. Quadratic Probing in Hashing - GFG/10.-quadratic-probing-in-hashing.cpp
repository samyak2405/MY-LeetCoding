// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int n)
    {
        for(int i = 0;i<hashSize;i++)
            hash.push_back(-1);
        
        for(int i = 0;i<n;i++)
        {
            int h = arr[i]%hashSize;
            if(hash[h]==-1)
                hash[h] = arr[i];
            else
            {
                int k = h;
                int power = 1;
                while(hash[(k+power*power)%hashSize]!=-1)
                    power++;
                hash[(k+power*power)%hashSize] = arr[i];
            }
        }
    }


};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    
	    int  N;
	    cin>>N;
	    int arr[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>arr[i];
	    
	    vector<int> hash (hashSize,-1);
	    Solution obj;
	    obj.QuadraticProbing (hash, hashSize, arr, N);
	    
	    for(int i = 0;i < hashSize; i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}


  // } Driver Code Ends