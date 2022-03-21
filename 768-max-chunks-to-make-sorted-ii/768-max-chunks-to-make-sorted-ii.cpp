class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int leftmax[n+1];
        leftmax[0] = arr[0];
        for(int i = 1;i<n;i++)
            leftmax[i] = max(leftmax[i-1],arr[i]);
        leftmax[n]=leftmax[n-1]; 
        int rightmin[n+1];
        rightmin[n] = INT_MAX;
        for(int i = n-1;i>=0;i--)
            rightmin[i] = min(rightmin[i+1],arr[i]);
        
        int chunk = 0;
        for(int i = 0;i<n;i++)
        {
            if(leftmax[i]<=rightmin[i+1])
                chunk++;
        }
        
        return chunk;
    }
};