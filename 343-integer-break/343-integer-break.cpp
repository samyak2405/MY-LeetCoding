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
        if(n%2)
            return f((n/2)+1,n);
        return f(n/2,n);
    }
};