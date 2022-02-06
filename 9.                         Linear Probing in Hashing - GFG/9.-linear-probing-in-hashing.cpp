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
        vector<int> myhash(hashSize,-1);
        
        for(int i = 0;i<n;i++)
        {
            int h = arr[i]%hashSize;
            int j = h;
            bool flag = false;
            while(myhash[j]!=-1)
            {
                if(myhash[j]==arr[i])
                {
                    flag=true;
                    break;
                }  
                j = (j+1)%hashSize;
                if(j==h)
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                continue;
            else
                myhash[j] = arr[i];
            
        }
        return myhash;
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