class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a or b or c)
        {
            if(c&1)
            {
                if(!(a&1) and !(b&1))
                    cnt++;
            }
            else
            {
                if(a&1 and b&1)
                    cnt+=2;
                else if(a&1 or b&1)
                    cnt++;
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return cnt;
    }
};