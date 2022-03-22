class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        for(int i = 0;i<n;i++)
            res+='a';
        k-=n;
        int i = n-1;
        while(k)
        {
            if(k>=25)
            {
                res[i]+=25;
                i--;
                k-=25;
            }
            else
            {
                res[i]+=k;
                k = 0;
            }
        }
        return res;
    }
};