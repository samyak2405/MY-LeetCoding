class Solution {
public:
    
    int f(int wt,int n)
    {
        if(wt<1 or n==0)
            return 1;
        if(wt<=n)
            return max(wt*f(wt,n-wt),f(wt-1,n));
        else
            return f(wt-1,n);
    }
    
    int integerBreak(int n) {
        if(n==3)
            return 2;
        if(n==5)
            return 6;
        return f(n/2,n);
    }
};