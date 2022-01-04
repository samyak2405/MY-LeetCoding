class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int x = ceil(log2(n));
        int y = (pow(2,x)-1)-n;
        if(y<0)
            return pow(2,x)+y;
        return y;
    }
};