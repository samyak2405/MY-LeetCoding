class Solution {
public:
    int arrangeCoins(int n) {
        long long low = -1,high = (long long)n+1;
        while(low+1<high)
        {
            long long mid = low+(high-low)/2;
            if((mid*(mid+1))/2<=n)
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};