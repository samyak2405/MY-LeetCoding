// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int n)
    {
        vector<int> hash(hashSize,-1);
        
        for(int i = 0;i<n;i++)
        {
            if(hash[arr[i]%hashSize]==-1)
                hash[arr[i]%hashSize]=arr[i];
            else
            {
                int k = arr[i]%hashSize;
                int cnt = 0;
                bool flag = false;
                while(cnt<hashSize and hash[k]!=-1)
                {
                    if(hash[k]==arr[i])
                    {
                        flag = true;
                        break;
                    }
                    k = (k+1)%hashSize;
                    cnt++;
                }
                if(flag)
                    continue;
                else
                    if(cnt<hashSize)
                        hash[k] = arr[i];
            }
        }
        return hash;
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
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    vector<int> hash;
	    Solution obj;
	    hash = obj.linearProbing( hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}

  // } Driver Code Ends