class Solution {
public:
    int mySqrt(int x) {
        if(x==0 or x==1)
            return x;
        int low = 0,high = x,ans;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(mid==x/mid)
                return mid;
            if(mid>=x/mid)
                high = mid-1;
            else
                low = mid+1,ans = mid;
        }
        return ans;
    }
};