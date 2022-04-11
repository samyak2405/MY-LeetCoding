class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a = 0;
        int limit = sqrt(c);
        long long int b = limit;
        while(a<=b)
        {
            if(a*a + b*b == c)
                return true;
            if(a*a + b*b >c)
                b--;
            else
                a++;
        }
        return false;
    }
};