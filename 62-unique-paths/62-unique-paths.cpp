class Solution {
public:
    
    int binomial(int n,int k)
    {
        if(k>n-k)
            k = n-k;
        long long int res = 1;
        
        for(int i = 0;i<k;i++)
        {
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    
    int uniquePaths(int m, int n) {
        return binomial(m+n-2,m-1);
    }
};