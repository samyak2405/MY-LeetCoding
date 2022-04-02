// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int binarySearch(int nums[],int start,int end,int key)
    {
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==key)
                return mid;
            if(nums[mid]<key)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
    
    int search(int nums[], int l, int h, int key){
        int start = l;
        int end = h;
        while(start<end)
        {
            if(nums[start]<nums[end])
                break;
            int mid = start+(end-start)/2;
            if(nums[mid]>=nums[start])
                start = mid+1;
            else
                end = mid;
        }
        int x = binarySearch(nums,l,start-1,key);
        int y = binarySearch(nums,start,h,key);
        return x!=-1?x:y;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends