class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)
            return false;
       int a = __builtin_ctz(n);
        int b = __builtin_popcount(n);
        if(b>1)
            return false;
        if(a%2)
            return false;
        return true;
    }
};