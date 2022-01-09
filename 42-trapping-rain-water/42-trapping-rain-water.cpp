class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxl(n,0),maxr(n,0);
        maxl[0] = height[0];
        maxr[n-1] = height[n-1];
        
        for(int i = 1;i<n;i++)
            maxl[i] = max(height[i],maxl[i-1]);
        for(int i = n-2;i>=0;i--)
            maxr[i] = max(height[i],maxr[i+1]);
        
        vector<int> res(n,0);
        for(int i = 0;i<n;i++)
            res[i] = min(maxl[i],maxr[i]);
        for(int i = 0;i<n;i++)
            res[i] = abs(res[i]-height[i]);
        
        int sum = 0;
        for(int i = 0;i<n;i++)
            sum += res[i];
        
        return sum;
    }
};